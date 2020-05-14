#ifndef SELECTBACKUPFOLDERDIALOG_H
#define SELECTBACKUPFOLDERDIALOG_H

#include "ui_selectbackupfolderdialog.h"
#include <QDialog>

class selectBackupFolderDialog : public QDialog {
  Q_OBJECT

public:
  selectBackupFolderDialog(QWidget *parent = 0,
                           const QString &controller = QString(),
                           const QStringList &list = QStringList());
  ~selectBackupFolderDialog();
  QString selectedBackup();

private:
  Ui::selectBackupFolderDialogClass ui;
};

#endif // SELECTBACKUPFOLDERDIALOG_H
