#ifndef CS8METAINFORMATIONMODEL_H
#define CS8METAINFORMATIONMODEL_H

//#include "logfilelineitem.h"
#include <logfilemodel.h>

#include <QSqlTableModel>
#define TABLE_NAME_LOG_FILES "tbLogFiles"

class cs8SystemConfigurationModel;

class cs8MetaInformationModel : public QSqlTableModel {
  Q_OBJECT
public:
  enum Preselection { Unset, Yes, No };
  Q_ENUM(Preselection)

  explicit cs8MetaInformationModel(QObject *parent = 0);
  cs8SystemConfigurationModel *systemConfigurationModel();
  void setLogData(logFileModel *logData);
  static Preselection dlgOpenSwapFile(qint64 hash);
  void setDlgOpenSwapFile(qint64 hash, Preselection value);
  static Preselection dlgIgnoreTimeGap(qint64 hash);
  static void setDlgIgnoreTimeGap(qint64 hash, Preselection value);
  static void resetDialogOptions();

  QString URLId() const;

  QString serialNumber() const;
  int hash() const;

signals:
  void metaInformationAvailable();

public slots:

private:
  logFileModel *m_model;
  cs8SystemConfigurationModel *m_systemConfigurationModel;
  int indexHashLogFile;
  int indexHashSwapFile;
  int indexIdControllers;
  int indexArchived;
  int indexSpanFrom;
  int indexSpanTill;
  int indexIdArms;
  int indexArmType;
  int indexDlgOpenSwap;
  int indexDlgIgnoreTimeGap;
  int indexFirstOpened;
  int indexLastOpen;
  bool firstTimeOpened;

  bool selectRecord(uint hash);
  void process(logFileModel *);

  protected slots:
  void slotProcessingConfigurationsFinished();

protected:
  QString m_URLId;
  QString m_serialNumber;
  void setLogfileInfo(uint hash, const QDateTime &spanFrom, const QDateTime &spanTill, const QString &machineNumber,
                      const QString &armType = QString());
};

#endif // CS8METAINFORMATIONMODEL_H
