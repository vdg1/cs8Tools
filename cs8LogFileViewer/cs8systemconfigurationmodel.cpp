//
// C++ Implementation: cs8systemconfigurationmodel
//
// Description:
//
//
// Author: Volker Drewer-Gutland <volker.drewer@gmx.de>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "cs8systemconfigurationmodel.h"
#include "cs8systemconfigurationset.h"
#include <QDebug>
#include <QFutureWatcher>
#include <QtConcurrent>

cs8SystemConfigurationModel::cs8SystemConfigurationModel(QObject *parent) : QStandardItemModel(parent) {
  m_futureWatcher.setFuture(m_future);
  // connect(&m_futureWatcher, SIGNAL(finished()), this,
  // SLOT(slotProcessingFinished()));
  connect(&m_futureWatcher, &QFutureWatcherBase::resultReadyAt, this,
          &cs8SystemConfigurationModel::slotProcessingFinished);
}

cs8SystemConfigurationModel::~cs8SystemConfigurationModel() { waitForFinished(); }

void cs8SystemConfigurationModel::waitForFinished() {
  if (!m_future.isFinished()) {
    qDebug() << "Waiting for system configuration reader completed";
    m_future.waitForFinished();
  }
}

QString cs8SystemConfigurationModel::machineSerialNumber(int idx) const {
  if (idx == -1) {
    cs8SystemConfigurationSet *systemSet;
    // retrieve last serial number
    for (int i = rowCount() - 1; i >= 0; i--) {
      systemSet = systemConfigurationSet(i);
      qDebug() << "setting: " << i << ":" << systemSet;
      if (!systemSet->machineNumber().isEmpty())
        return systemConfigurationSet(i)->machineNumber();
    }
    // return empty string if no configuration set contains serial number
    return QString();
  } else {
    // retrieve specific serial number
    return systemConfigurationSet(idx)->machineNumber();
  }
}

QString cs8SystemConfigurationModel::armSerialNumber(int idx) const {
  if (idx == -1) {
    cs8SystemConfigurationSet *systemSet;
    // retrieve last serial number
    for (int i = rowCount() - 1; i >= 0; i--) {
      systemSet = systemConfigurationSet(i);
      qDebug() << "setting: " << i << ":" << systemSet;
      if (!systemSet->armNumber().isEmpty())
        return systemConfigurationSet(i)->armNumber();
    }
    // return empty string if no configuration set contains arm serial number
    return QString();
  } else {
    // retrieve specific serial number
    return systemConfigurationSet(idx)->armNumber();
  }
}

QDateTime cs8SystemConfigurationModel::timeStampFrom(int idx) const {
  if (idx == -1) {
    // retrieve last serial number
    for (int i = rowCount() - 1; i >= 0; i--) {
      if (!systemConfigurationSet(i)->timeStampFrom().isNull())
        return systemConfigurationSet(i)->timeStampFrom();
    }
    // return empty string if no configuration set contains serial number
    return QDateTime();
  } else {
    // retrieve specific serial number
    return systemConfigurationSet(idx)->timeStampFrom();
  }
}

QList<cs8SystemConfigurationSet *> cs8SystemConfigurationModel::parseSystemSettings(logFileModel *logText) {
  qDebug() << "cs8SystemConfigurationModel::parseSystemSettings";
  int line = logText->lastValidLineWithTimeStamp();
  int systemStart;
  int lastSystemStart = line - 1;
  int pos;

  QRegExp systemStartRx;
  systemStartRx.setPattern("^\\-{10,}$");

  configurationList configSets;
  cs8SystemConfigurationSet *systemSet;

  while (line > 0) {
    systemStart = qMax(0, logText->messageList().lastIndexOf(systemStartRx, line));
    systemSet = new cs8SystemConfigurationSet();
    systemSet->setFrom(systemStart + 1,
                       logText->logTimeStamp(systemStart + 1)); //  logText.at(systemStart+1).timeStamp);
    systemSet->setTo(lastSystemStart + 1,
                     logText->logTimeStamp(lastSystemStart + 1)); // logText.at(lastSystemStart+1).timeStamp);

    qDebug() << "collecting system information from " << systemStart << " to " << lastSystemStart << ":"
             << logText->logTimeStamp(systemStart + 1).toString(Qt::ISODate) << " to "
             << logText->logTimeStamp(lastSystemStart + 1).toString(Qt::ISODate);
    for (int i = systemStart; i < lastSystemStart; i++) {
      foreach (cs8SystemConfigurationItem *item, systemSet->items()) {
        // qDebug() << item->rx.pattern();
        pos = item->rx.indexIn(logText->messageList().at(i));
        if (pos != -1) {
          // qDebug() << "captured set: " << item->rx.cap(2) << " in " <<
          // logText->messageList().at(i) << item->rx.pattern();
          item->value = item->rx.cap(3).trimmed().replace('/', '_');
          item->line = line;
          break;
        }
      }
    }
    qDebug() << "collecting system information from " << systemStart << " to " << lastSystemStart << ": done";

    configSets.append(systemSet);
    // QStandardItem *item=new QStandardItem();
    // item->setData(qVariantFromValue(systemSet), Qt::UserRole);
    // qDebug() << "adding system set: " << systemSet->from() << " - " <<
    // systemSet->to();  insertRow( 0, item);

    line = systemStart - 1;
    lastSystemStart = line;
  }

  // reprocess();
  return configSets;
}

void cs8SystemConfigurationModel::reprocess() {
  /*
  if (rowCount() > 1) {
    systemConfigurationSet(1)->setFrom(
        systemConfigurationSet(0)->from(),
        systemConfigurationSet(0)->timeStampFrom());
    delete systemConfigurationSet(0);
    removeRow(0);
  }

  // remove empty system settings (e.g. no complete system start
  for (int i = 0; i < rowCount(); i++) {
    cs8SystemConfigurationSet *a = systemConfigurationSet(i);
    if (a->isEmpty() && (systemConfigurationSet(i + 1) != 0)) {
      // merge start of set into next set
      cs8SystemConfigurationSet *b = systemConfigurationSet(i + 1);
      b->setFrom(a->from(), a->timeStampFrom());
      delete systemConfigurationSet(i);
      removeRow(i);
    }
  }
  */

  //
  // remove empty system settings (e.g. no complete system start
  int i = 0;
  while (i < rowCount()) {
    cs8SystemConfigurationSet *a = systemConfigurationSet(i);
    if (a->isEmpty()) {
      qDebug() << "Remove empty configuration" << a;
      cs8SystemConfigurationSet *next = i + 1 < rowCount() ? systemConfigurationSet(i + 1) : nullptr;
      cs8SystemConfigurationSet *previous = i > 0 ? systemConfigurationSet(i - 1) : nullptr;
      if (next) {
        next->setFrom(a->from(), a->timeStampFrom());
      } else if (previous) {
        previous->setTo(a->to(), a->timeStampTo());
      }
      removeRow(i);
      delete a;
    } else {
      i++;
    }
  }

  // merge adjacent system settings containing same settings/information
  for (int i = 0; i < rowCount(); i++) {
    cs8SystemConfigurationSet *a = systemConfigurationSet(i);
    while ((i < rowCount() - 1)) {
      cs8SystemConfigurationSet *b = systemConfigurationSet(i + 1);
      if (a->isEqual(b)) {
        qDebug() << "merge configurations a: " << a << " and " << b;
        a->setTo(b->to(), b->timeStampTo());
        a->setWorkingHours(b->workingHours());
        delete systemConfigurationSet(i + 1);
        removeRow(i + 1);
      } else
        break;
    }
  }

  for (int i = 0; i < rowCount(); i++) {
    cs8SystemConfigurationSet *set = systemConfigurationSet(i);
    qDebug() << "configuration set: " << i << ":" << set;
    emit systemConfigurationSetDetected(set);
  }
  qDebug() << "reprocessing completed, found configurations sets:" << rowCount();
}

void cs8SystemConfigurationModel::setLogData(logFileModel *logData) {
  clear();
  m_future = QtConcurrent::run(parseSystemSettings, logData);
  m_futureWatcher.setFuture(m_future);
}

void cs8SystemConfigurationModel::setMachineInfo(const QString &customer, const QString &internalNumber,
                                                 const QString &machineNumber, const QString &workingHours) {
  QStandardItem *customerItem = nullptr;
  for (int i = 0; i < rowCount(); i++) {

    if (item(i, 0)->text() == tr("Robot Information")) {
      customerItem = item(i, 0);
      break;
    }
  }
  if (customerItem == nullptr) {
    customerItem = new QStandardItem(tr("Robot Information"));
    insertRow(0, QList<QStandardItem *>() << customerItem << new QStandardItem());
  }
  customerItem->appendRow(QList<QStandardItem *>()
                          << new QStandardItem(tr("Customer:")) << new QStandardItem(tr("%1").arg(customer)));
  customerItem->appendRow(QList<QStandardItem *>() << new QStandardItem(tr("Internal Number:"))
                                                   << new QStandardItem(tr("%1").arg(internalNumber)));
  customerItem->appendRow(QList<QStandardItem *>() << new QStandardItem(tr("Machine Number:"))
                                                   << new QStandardItem(tr("%1").arg(machineNumber)));

  qDebug() << "Column Counts: " << columnCount() << columnCount(customerItem->index());
}

void cs8SystemConfigurationModel::clear() {
  m_future.cancel();
  m_future.waitForFinished();
  QStandardItemModel::clear();
}

/*!
   \fn cs8SystemConfigurationModel::systemConfigurationSet(int idx=-1)
 */
cs8SystemConfigurationSet *cs8SystemConfigurationModel::systemConfigurationSet(int idx) const {
  /// TODO m_future.waitForFinished();
  // check if idx is in bounds
  if (idx < rowCount() && rowCount() != 0)
    return data(index(idx == -1 ? rowCount() - 1 : idx, 0), Qt::UserRole).value<cs8SystemConfigurationSet *>();
  else
    return nullptr; // new cs8SystemConfigurationSet();
}

cs8SystemConfigurationSet *cs8SystemConfigurationModel::systemConfigurationSetAtLine(int row) const {
  for (int i = 0; i < rowCount(); i++) {
    cs8SystemConfigurationSet *set = systemConfigurationSet(i);
    if (set->from() <= row && set->to() > row)
      return set;
  }
  return new cs8SystemConfigurationSet();
}

void cs8SystemConfigurationModel::slotProcessingFinished() {
  // qDebug() << "processing ready";
  // qDebug() << "count: " << m_future.resultCount();
  if (m_future.resultCount() > 0) {
    // retrieve found system settings and store them in model
    configurationList list = m_future.result();
    foreach (cs8SystemConfigurationSet *systemSet, list) {
      QStandardItem *item = new QStandardItem();
      item->setData(qVariantFromValue(systemSet), Qt::UserRole);
      insertRow(0, QList<QStandardItem *>() << item << new QStandardItem());
    }

    // reprocess model: merge system settings....
    reprocess();

    // append child items with detailed system information
    for (int row = 0; row < rowCount(); row++) {
      cs8SystemConfigurationSet *systemSet = systemConfigurationSet(row);
      qDebug() << "Build setting tree: " << row << ":" << systemSet;
      // retrieve previous set
      cs8SystemConfigurationSet *previousSet;
      if (row > 0)
        previousSet = systemConfigurationSet(row - 1);
      else
        previousSet = nullptr;

      item(row, 0)->setText(
          QStringLiteral("System configuration from line %1 to line %2").arg(systemSet->from()).arg(systemSet->to()));

      item(row, 0)->setToolTip(QStringLiteral("System configuration from %1 to %2")
                                   .arg(systemSet->timeStampFrom().toString(Qt::SystemLocaleLongDate))
                                   .arg(systemSet->timeStampTo().toString(Qt::SystemLocaleLongDate)));

      QHashIterator<QString, cs8SystemConfigurationItem *> i(systemSet->items());
      while (i.hasNext()) {
        i.next();
        if (!i.value()->value.isEmpty()) {
          QStandardItem *childItemTitle = new QStandardItem(i.key());
          QStandardItem *childItemValue = new QStandardItem(i.value()->value);
          childItemValue->setToolTip(childItemValue->text());

          item(row, 0)->appendRow(QList<QStandardItem *>() << childItemTitle << childItemValue);
          if (previousSet != nullptr) {
            // check if previous set also contains current item
            if (previousSet->items().contains(i.key())) {
              //
              QString val = previousSet->items().value(i.key())->value;
              if (!val.isEmpty()) {
                // Setting has changed compared to previous configuration
                if (val != i.value()->value) {
                  childItemTitle->setBackground(QBrush(Qt::red));
                  childItemTitle->setToolTip(tr("Setting has changed compared to previous "
                                                "configuration"));
                }
              } else {
                // Setting does not exist in previous configuration
                childItemTitle->setBackground(QBrush(Qt::gray));
                childItemTitle->setToolTip(tr("Setting does not exist in previous configuration"));
              }
            }
          }
        }
      }
    }
  }
  emit completed();
}
/*
int cs8SystemConfigurationModel::rowCount() const {
  if (!m_future.isFinished()) {
    qDebug() << "Processing not finished yet";
    return 0;
  }
  /// TODO m_future.waitForFinished();
  return QStandardItemModel::rowCount();
}
*/
