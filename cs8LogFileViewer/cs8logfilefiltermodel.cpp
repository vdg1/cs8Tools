#include "cs8logfilefiltermodel.h"

#include <QSortFilterProxyModel>

cs8LogFileFilterModel::cs8LogFileFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent), m_hideUserMessages(false), m_hideSwapFileMessages(false), m_reverseOrder(false) {

  setFilterRegExp(QRegExp("((^|^<0x\\d{4}> )USR:)"));
  setDynamicSortFilter(true);
}

void cs8LogFileFilterModel::setSourceModel(logFileModel *model) {
  QSortFilterProxyModel::setSourceModel(model);
  m_model = model;
}

void cs8LogFileFilterModel::setHideUserMessages(bool hide) {
  if (hide != m_hideUserMessages) {
    m_hideUserMessages = hide;
    invalidateFilter();
  }
}

void cs8LogFileFilterModel::setHideSwapFileMessages(bool hide) {
  if (hide != m_hideSwapFileMessages) {
    m_hideSwapFileMessages = hide;
    invalidateFilter();
  }
}

bool cs8LogFileFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const {
  bool acceptRow = true;

  if (m_hideSwapFileMessages)
    if (sourceRow <= m_model->swapLineCount())
      acceptRow = false;

  if (m_model->fileType() == cs8LogFileData::CS8) {
    QModelIndex index1 = m_model->index(sourceRow, 2, sourceParent);
    if (m_hideUserMessages)
      if (m_model->data(index1).toString().contains(filterRegExp()))
        acceptRow = false;
  } else {
    QModelIndex index1 = m_model->index(sourceRow, 1, sourceParent);
    int level = m_model->data(index1, Qt::UserRole).toInt();
    if (!m_showError && level == cs8LogFileData::Error)
      acceptRow = false;
    if (!m_showWarning && level == cs8LogFileData::Warning)
      acceptRow = false;
    if (!m_showInformation && level == cs8LogFileData::Information)
      acceptRow = false;
  }

  return acceptRow;
}

bool cs8LogFileFilterModel::lessThan(const QModelIndex &left, const QModelIndex &right) const {
  // for CS8 log files sort according to line numbers
  // CS9 logs must be sorted according to time stamp of message

  logFileModel *model = qobject_cast<logFileModel *>(sourceModel());

  QModelIndex l = model->index(left.row(), 0);
  QModelIndex r = model->index(right.row(), 0);

  if (model->fileType() == cs8LogFileData::CS9) {
    //(double)m_logData[index.row()].ns/1000+m_logData[index.row()].date.toMSecsSinceEpoch()
    qint64 ms = model->data(l).toDateTime().toMSecsSinceEpoch();
    double ns = (model->data(l, Qt::UserRole).toDouble());
    ns = ns / 1000;
    double leftTime = ms + ns;

    ms = model->data(r).toDateTime().toMSecsSinceEpoch();
    ns = (model->data(r, Qt::UserRole).toDouble());
    ns = ns / 1000;
    double rightTime = ms + ns;

    if (left.row() >= 223 && left.row() <= 226) {
      qDebug() << "left: " << leftTime << "right: " << rightTime;
    }
    return leftTime > rightTime;
  } else
    return l.row() > r.row();
}

bool cs8LogFileFilterModel::showError() const { return m_showError; }

void cs8LogFileFilterModel::setShowError(bool showError) {
  m_showError = showError;
  invalidateFilter();
}

bool cs8LogFileFilterModel::showWarning() const { return m_showWarning; }

void cs8LogFileFilterModel::setShowWarning(bool showWarning) {
  m_showWarning = showWarning;
  invalidateFilter();
}

bool cs8LogFileFilterModel::showInformation() const { return m_showInformation; }

void cs8LogFileFilterModel::setShowInformation(bool showInformation) {
  m_showInformation = showInformation;
  invalidateFilter();
}

bool cs8LogFileFilterModel::reverseOrder() const { return m_reverseOrder; }

void cs8LogFileFilterModel::setReverseOrder(bool reverseOrder) {
  m_reverseOrder = reverseOrder;
  emit orderChanged(m_reverseOrder);
  sort(1, !m_reverseOrder ? Qt::DescendingOrder : Qt::AscendingOrder);
}

bool cs8LogFileFilterModel::hideSwapFileMessages() const { return m_hideSwapFileMessages; }

bool cs8LogFileFilterModel::hideUserMessages() const { return m_hideUserMessages; }
