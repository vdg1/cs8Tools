#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QDebug>
#include <QDirIterator>
#include <QDomDocument>
#include <QFile>

aboutDialog::aboutDialog(const QString &releaseNotesFile, QWidget *parent) : QDialog(parent), ui(new Ui::aboutDialog) {

  ui->setupUi(this);
  ui->labelVersion->setText(qApp->applicationVersion());

  QFile file(releaseNotesFile);
  qDebug() << "release notes file:" << file.fileName() << " exists:" << file.exists();
  if (file.open(QFile::ReadOnly))
    ui->textEditChangelog->setPlainText(file.readAll());
  this->setWindowTitle(tr("About %1").arg(qApp->applicationName()));
}

aboutDialog::~aboutDialog() { delete ui; }

void aboutDialog::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}
