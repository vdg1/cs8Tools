#ifndef DIALOGMACHINECATALOGUEIMPORTCONFIGURATION_H
#define DIALOGMACHINECATALOGUEIMPORTCONFIGURATION_H

#include "ui_dialogmachinecatalogueimportconfiguration.h"
#include "xlstablemodel.h"
#include <QItemSelection>
#include <QSortFilterProxyModel>
#include <QtWidgets/QDialog>

namespace Ui {
class DialogMachineCatalogueImportConfiguration;
}

class DialogMachineCatalogueImportConfiguration : public QDialog {
  Q_OBJECT

public:
  explicit DialogMachineCatalogueImportConfiguration(QWidget *parent, const QString &filePath);
  ~DialogMachineCatalogueImportConfiguration();
  void setCatalogueFile(const QString &filePath);

protected:
  void changeEvent(QEvent *e);

private slots:
  void selectRow(int row);
  void on_cbWithHeader_toggled(bool arg1);
  void selectionChanged(QModelIndex selected, QModelIndex);

  void on_buttonBox_accepted();
  void on_sbCustomerName_valueChanged(int);

  void on_sbInternalNumber_valueChanged(int);

  void on_sbUrlId_valueChanged(int);

  void on_sbControllerSerialNumber_valueChanged(int);

  void on_sbArmSerialNumber_valueChanged(int);

private:
  Ui::DialogMachineCatalogueImportConfiguration *ui;
  xlsTableModel *m_model;
  QSortFilterProxyModel *m_proxyModel;
  QString m_catalogueFilePath;

  void updatedSelectedRowData();
};

#endif // DIALOGMACHINECATALOGUEIMPORTCONFIGURATION_H
