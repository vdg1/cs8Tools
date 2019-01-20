#ifndef DIALOGGETMACHINEDATA_H
#define DIALOGGETMACHINEDATA_H

#include "cs8serialnumbervalidator.h"
#include <QtWidgets/QDialog>

namespace Ui {
class DialogGetMachineData;
}

class DialogGetMachineData : public QDialog {
  Q_OBJECT

public:
  explicit DialogGetMachineData(QWidget *parent = 0);
  ~DialogGetMachineData();
  void setSerialNumber(const QString &serialNumber);
  void remoteCatalogue();
  void setInfoText(const QString &text);
  QString backupPath() const;
  QString customer() const;
  QString internalNumber() const;

protected:
  void changeEvent(QEvent *e);

private slots:
  void on_buttonBox_accepted();

private:
  Ui::DialogGetMachineData *ui;
  QString headerText;
  QString m_serialNumber;
  cs8SerialNumberValidator *m_validator;
};

#endif // DIALOGGETMACHINEDATA_H
