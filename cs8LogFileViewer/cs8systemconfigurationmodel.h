//
// C++ Interface: cs8systemconfigurationmodel
//
// Description:
//
//
// Author: Volker Drewer-Gutland <volker.drewer@gmx.de>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef CS8SYSTEMCONFIGURATIONMODEL_H
#define CS8SYSTEMCONFIGURATIONMODEL_H

#include "logfilemodel.h"

#include <QFutureWatcher>
#include <QStandardItemModel>

/**
 @author Volker Drewer-Gutland <volker.drewer@gmx.de>
 */

class cs8SystemConfigurationSet;

class cs8SystemConfigurationModel : public QStandardItemModel {
  Q_OBJECT
public:
    explicit cs8SystemConfigurationModel(QObject *parent = nullptr);
    ~cs8SystemConfigurationModel();

    cs8SystemConfigurationSet *systemConfigurationSet(int idx = -1) const;
    cs8SystemConfigurationSet *systemConfigurationSetAtLine(int row = 0) const;
    // int rowCount() const;
    void waitForFinished();
    QString machineSerialNumber(int idx = -1) const;
    QString armSerialNumber(int idx = -1) const;
    QDateTime timeStampFrom(int idx = -1) const;

public slots:
  void setLogData(logFileModel *logData);
  void setMachineInfo(const QString &customer, const QString &internalNumber,
                      const QString &machineNumber, const QString &);
  void clear();

signals:
  void systemConfigurationSetDetected(cs8SystemConfigurationSet *);
  void completed();

protected:
  typedef QList<cs8SystemConfigurationSet *> configurationList;
  QFutureWatcher<configurationList> m_futureWatcher;
  QFuture<configurationList> m_future;
  static QList<cs8SystemConfigurationSet *> parseSystemSettings(logFileModel *logText);
  void reprocess();

protected slots:
  void slotProcessingFinished();
};

#endif
