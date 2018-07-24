#include "cs8checkupdate.h"

#include <QApplication>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include <QXmlInputSource>

cs8CheckUpdate::cs8CheckUpdate(QObject *parent) : QObject(parent), m_notifyOnSuccess(false), m_notifyOnError(false) {
  m_maintenaceProcess = new QProcess();

  QString updateProgram = qApp->applicationDirPath() + "/maintenancetool.exe";
  if (!QFile::exists(updateProgram))
    updateProgram = qApp->applicationDirPath() + "/cs8ToolsMaintenanceTool.exe";
  m_maintenaceProcess->setProgram(updateProgram);

  connect(m_maintenaceProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this,
          SLOT(slotFinished(int, QProcess::ExitStatus)));
  connect(m_maintenaceProcess, &QProcess::errorOccurred, this, &cs8CheckUpdate::slotError);
  connect(this, &cs8CheckUpdate::checkCompleted, this, &cs8CheckUpdate::slotCheckCompleted);

  m_checkTimer = new QTimer(this);
  connect(m_checkTimer, &QTimer::timeout, this, &cs8CheckUpdate::slotCheckTimer);
}

void cs8CheckUpdate::checkForUpdates(const bool notifyOnSuccess, const bool notifyOnError) {
  if (m_maintenaceProcess->state() == QProcess::NotRunning) {
    qDebug() << "Started update check:" << m_maintenaceProcess->program() << m_maintenaceProcess->arguments();
    m_maintenaceProcess->setArguments(QStringList() << "--checkupdates");
    m_maintenaceProcess->start();
    m_notifyOnSuccess = notifyOnSuccess;
    m_notifyOnError = notifyOnError;
  } else {
    QMessageBox::information(qApp->topLevelWidgets().at(0), tr("cs8Tools Update Check"),
                             tr("An update check is already active!"));
  }
}

void cs8CheckUpdate::enableRegularCheck(int intervalInMin) {
  if (intervalInMin != 0)
    m_checkTimer->start(intervalInMin * 60 * 1000);
  else
    m_checkTimer->stop();
}

void cs8CheckUpdate::slotFinished(int /*exitCode*/, QProcess::ExitStatus exitStatus) {
  if (exitStatus == QProcess::NormalExit) {
    // read output channel
    QString output = m_maintenaceProcess->readAllStandardOutput();
    qDebug() << "maintenance.exe output: " << output;

    QRegExp rxName;
    rxName.setPattern("name=\\\"(.*)\\\"");
    rxName.setMinimal(true);
    QRegExp rxVersion;
    rxVersion.setPattern("version=\\\"(.*)\\\"");
    rxVersion.setMinimal(true);
    int pos = 0;
    QStringList updatedModules;
    QStringList versions;
    foreach (QString line, output.split("\n")) {
      pos = 0;
      while ((pos = rxName.indexIn(line, pos)) != -1) {
        updatedModules << rxName.cap(1);
        pos += rxName.matchedLength();
      }
      pos = 0;
      while ((pos = rxVersion.indexIn(line, pos)) != -1) {
        versions << rxVersion.cap(1);
        pos += rxVersion.matchedLength();
      }
    }
    emit checkCompleted(updatedModules, versions, false);

  } else {
    // error occured during execution of maintenance.exe
    emit checkCompleted(QStringList(), QStringList(), true);
  }
}

void cs8CheckUpdate::slotError(QProcess::ProcessError error) {
  qDebug() << "maintenance tool error occured:" << error;
  emit checkCompleted(QStringList(), QStringList(), true);
}

void cs8CheckUpdate::slotCheckCompleted(const QStringList &updates, const QStringList &versions, bool error) {

  if (error) {
    if (m_notifyOnError)
      QMessageBox::warning(qApp->topLevelWidgets().at(0), tr("cs8Tools Update Check"),
                           tr("An error occured during update check. Try again later!"));
  } else {
    if (m_notifyOnSuccess)
      if (updates.count() > 0) {
        QStringList updateList;
        for (int i = 0; i < updates.count(); i++)
          updateList << QString("%1 (%2)").arg(updates.at(i)).arg(versions.at(i));

        if (QMessageBox::question(qApp->topLevelWidgets().at(0), tr("cs8Tools Update Check"),
                                  tr("An update of following module(s) is available:\n%1\nDo you "
                                     "want to install the updates?")
                                      .arg(updateList.join("\n")),
                                  QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton) == QMessageBox::Yes) {
          QProcess maintenance;
          maintenance.startDetached(m_maintenaceProcess->program(), QStringList() << "--updater");
        }
      } else {
        if (m_notifyOnError)
          QMessageBox::information(qApp->topLevelWidgets().at(0), tr("cs8Tools Update Check"),
                                   tr("No updates available!"));
      }
  }
}

void cs8CheckUpdate::slotCheckTimer() { checkForUpdates(true, false); }
