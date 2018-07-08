#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QDebug>
#include <QDirIterator>
#include <QDomDocument>
#include <QFile>

aboutDialog::aboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::aboutDialog) {

  ui->setupUi(this);
  ui->labelVersion->setText(qApp->applicationVersion());
  setWindowTitle(tr("About %1").arg(qApp->applicationName()));
  //:/releasenotes.txt
  QFile file("qrc:/releasenotes.txt");
  qDebug() << "release notes file:" << file.fileName() << " exists:" << file.exists();
  if (file.open(QFile::ReadOnly))
    ui->textEditChangelog->setPlainText(file.readAll());
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
