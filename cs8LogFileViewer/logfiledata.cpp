#include "logfiledata.h"

#include <QDebug>
#include <QStringList>

logFileData::logFileData() = default;

QStringList logFileData::updateCache() {
  if (size() != m_messageCache.size()) {
    qDebug() << "updating message cache from " << m_messageCache.size() << " to " << size();
    int startIdx = m_messageCache.size();
    while (startIdx < size()) {
      m_messageCache << at(startIdx).message;
      startIdx++;
    }
  }
  return QStringList(m_messageCache);
}

QStringList logFileData::toStringList() { return updateCache(); }

QStringList logFileData::messageTypes() {
  QStringList types;
  for (int i = 0; i < size(); ++i) {
    types << at(i).type;
  }
  return types;
}

int logFileData::lastValidLine() const {
  for (int i = size() - 1; i >= 0; i--) {
    if (at(i).date.isValid())
      return i;
  }
  return 0;
}
