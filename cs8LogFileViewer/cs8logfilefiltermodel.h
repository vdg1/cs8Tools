#ifndef CS8LOGFILEFILTERMODEL_H
#define CS8LOGFILEFILTERMODEL_H

#include "logfilemodel.h"

#include <QSortFilterProxyModel>

class cs8LogFileFilterModel : public QSortFilterProxyModel {
  Q_OBJECT

public:
  explicit cs8LogFileFilterModel(QObject *parent = 0);
  // bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

  void setSourceModel(logFileModel *model);
  void setHideUserMessages(bool hide);
  void setHideSwapFileMessages(bool hide);

  bool hideUserMessages() const;

  bool hideSwapFileMessages() const;

  bool reverseOrder() const;
  void setReverseOrder(bool reverseOrder);
  QString getLines(int start, int count);

signals:
  bool orderChanged(bool reversed);

protected:
  bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
  bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

  // bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

private:
  bool m_hideUserMessages, m_hideSwapFileMessages, m_reverseOrder;
  logFileModel *m_model;
};

#endif // CS8LOGFILEFILTERMODEL_H
