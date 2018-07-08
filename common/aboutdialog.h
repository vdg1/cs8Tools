#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtWidgets/QDialog>

namespace Ui {
class aboutDialog;
}

class aboutDialog : public QDialog {
  Q_OBJECT

public:
  explicit aboutDialog(QWidget *parent = Q_NULLPTR);
  ~aboutDialog();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::aboutDialog *ui;
};

#endif // ABOUTDIALOG_H
