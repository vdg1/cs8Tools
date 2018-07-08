#ifndef CS8CHECKUPDATE_H
#define CS8CHECKUPDATE_H

#include <QObject>
#include <QProcess>
#include <QTimer>

class cs8CheckUpdate : public QObject {
  Q_OBJECT
public:
  explicit cs8CheckUpdate(QObject *parent = nullptr);

signals:
  void checkCompleted(const QStringList &updates, const QStringList &versions,
                      bool error);

public slots:
  void checkForUpdates(const bool notifyOnSuccess = true,
                       const bool notifyOnError = false);
  void enableRegularCheck(int intervalInMin = 1);

protected slots:
  void slotFinished(int, QProcess::ExitStatus exitStatus);
  void slotError(QProcess::ProcessError error);
  void slotCheckCompleted(const QStringList &updates,
                          const QStringList &versions, bool error);
  void slotCheckTimer();

protected:
  bool m_notifyOnSuccess;
  bool m_notifyOnError;
  QProcess *m_maintenaceProcess;
  QTimer *m_checkTimer;
};

#endif // CS8CHECKUPDATE_H
