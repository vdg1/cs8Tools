#ifndef CS8CONNECTDIALOG_H
#define CS8CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class cs8ConnectDialog;
}

class cs8ConnectDialog : public QDialog {
  Q_OBJECT

 public:
  explicit cs8ConnectDialog(QWidget *parent = 0);
  ~cs8ConnectDialog();
  QString address() const;
  quint16 port() const;
  bool loadLogFile() const;

 protected:
  void changeEvent(QEvent *e);

 protected slots:
  void accepted();

 private slots:
  void on_cpIPAddress_currentTextChanged(const QString &arg1);

 private:
  Ui::cs8ConnectDialog *ui;
};

#endif  // CS8CONNECTDIALOG_H
