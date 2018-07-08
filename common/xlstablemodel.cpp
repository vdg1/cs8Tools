#include "xlstablemodel.h"

xlsTableModel::xlsTableModel(QObject *parent)
    : QAbstractTableModel(parent), m_xlsData(nullptr), m_withHeader(false) {}

int xlsTableModel::rowCount(const QModelIndex & /* parent */) const {
  return dynamic_cast<QXlsx::Worksheet *>(m_xlsData->currentSheet())
             ->dimension()
             .lastRow() -
         (m_withHeader ? 1 : 0);
}

int xlsTableModel::columnCount(const QModelIndex & /* parent */) const {
  return dynamic_cast<QXlsx::Worksheet *>(m_xlsData->currentSheet())
      ->dimension()
      .lastColumn();
}

QVariant xlsTableModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || m_xlsData == nullptr)
    return QVariant();

  switch (role) {
  case Qt::DisplayRole:
    return m_xlsData->read(index.row() + 1 + (m_withHeader ? 1 : 0),
                           index.column() + 1);
    break;
  }
  return QVariant();
}

QVariant xlsTableModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const {
  if (section > columnCount() || orientation != Qt::Horizontal ||
      role != Qt::DisplayRole || m_xlsData == nullptr || !m_withHeader)
    return QVariant();

  return m_xlsData->read(1, section + 1);
}

bool xlsTableModel::withHeader() const { return m_withHeader; }

void xlsTableModel::setWithHeader(bool withHeader) {
  beginResetModel();
  m_withHeader = withHeader;
  endResetModel();
}

void xlsTableModel::setSource(const QString &fileName, bool withHeader) {
  beginResetModel();
  // clear previous file
  if (m_xlsData != nullptr) {
    delete m_xlsData;
  }

  m_withHeader = withHeader;
  m_xlsData = new QXlsx::Document(fileName, this);
  endResetModel();
}
