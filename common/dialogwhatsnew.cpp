#include "dialogwhatsnew.h"
#include "ui_dialogwhatsnew.h"

#include <QFile>

DialogWhatsNew::DialogWhatsNew(QWidget *parent) : QDialog(parent), ui(new Ui::DialogWhatsNew) {
  ui->setupUi(this);
  //:/releasenotes.txt
  QFile file(":/releasenotes.txt");
  if (file.open(QFile::ReadOnly))
    ui->textEditChangelog->setPlainText(file.readAll());
}

DialogWhatsNew::~DialogWhatsNew() { delete ui; }
