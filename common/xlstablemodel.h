#ifndef XLSTABLEMODEL_H
#define XLSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <xlsxdocument.h>

class xlsTableModel : public QAbstractTableModel {
public:
  xlsTableModel(QObject *parent = Q_NULLPTR);
  void setSource(const QString &fileName, bool withHeader = false);

  // QAbstractItemModel interface
public:
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;

  bool withHeader() const;
  void setWithHeader(bool withHeader);

protected:
  bool m_withHeader;
  QXlsx::Document *m_xlsData;
};

#endif // XLSTABLEMODEL_H
