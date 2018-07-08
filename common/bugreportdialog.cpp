#include "bugreportdialog.h"
#include "ui_bugreportdialog.h"

#include <QDesktopServices>
#include <QDir>
#include <QMessageBox>
#include <QUrl>

bugReportDialog::bugReportDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::bugReportDialog) {
  ui->setupUi(this);
  setWindowIcon(qApp->windowIcon());
  m_recipient =
      "cs8-backup-bug-tracking.437db1b7@swiss-software.saxe-group.podio.com";
  m_attachUrl = "";
}

bugReportDialog::~bugReportDialog() { delete ui; }

void bugReportDialog::setAttachment(const QString &url) { m_attachUrl = url; }

void bugReportDialog::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void bugReportDialog::on_pushButton_2_clicked() {
  if (!ui->subject->text().isEmpty() &&
      !ui->description->toPlainText().isEmpty()) {
    QString body = QString("Bug: %5\n\n"
                           "Version: %6\n\n"
                           "Priority: %3\n\n"
                           "Type of issue: %4\n\n"
                           "Description of problem: %1\n\n"
                           "Steps to reproduce: %2\n\n")
                       .arg(ui->description->toPlainText().trimmed())
                       .arg(ui->reproduce->toPlainText().trimmed())
                       .arg(ui->severity->currentText())
                       .arg(ui->type->currentText())
                       .arg(ui->subject->text().trimmed())
                       .arg(qApp->applicationVersion());

    QString data =
        QString("mailto:%1?subject=%2&body=%3")
            .arg(m_recipient)
            .arg(ui->subject->text())
            .arg(body); //.arg(QDir::toNativeSeparators(m_attachUrl));
    QUrl url(data);

    QDesktopServices::openUrl(url);
    close();
  } else {
    QMessageBox::information(
        this, tr("Submit a bug report"),
        tr("You have to fill in at least 'Subject' and 'Description' in order "
           "to submit a bug report!"));
  }
}
