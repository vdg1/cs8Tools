#ifndef MACHINECATALOGUE_H
#define MACHINECATALOGUE_H

#include <QFileInfo>
#include <QObject>
#include <QSqlTableModel>

#define CATALOGUE_FILENAME "Catalogue.csv"

class machineCatalogue : public QObject {
  Q_OBJECT
  Q_PROPERTY(uint controllerSerialNumberColumn READ controllerSerialNumberColumn WRITE setControllerSerialNumberColumn)
  Q_PROPERTY(uint customerNameColumn READ customerNameColumn WRITE setCustomerNameColumn)
  Q_PROPERTY(uint internalNumberColumn READ internalNumberColumn WRITE setInternalNumberColumn)

  Q_PROPERTY(uint URLIdColumn READ URLIdColumn WRITE setURLIdColumn)

  Q_PROPERTY(bool withHeader READ withHeader WRITE setWithHeader)

public:
  explicit machineCatalogue(QObject *parent = nullptr);
  QStringList remoteCatalogue(const QString &storageBasePath, const QString &base);

  qint32 controllerSerialNumberColumn() const;

  qint32 armSerialNumberColumn() const;

  qint32 customerNameColumn() const;

  qint32 internalNumberColumn() const;

  bool withHeader() const;
  QStringList customers() const;
  QStringList internalNumbers() const;
  QString filePath() const;
  bool findByMachineNumber(const QString &serialNumber, QString &customer, QString &internalNumber, QString &UrlId);

  qint32 URLIdColumn() const;

  QString appData() const;
  bool importFile(const QString &fileName);
  int entries() const;
  bool addLocalEntry(const QString &controllerSerialNumber, const QString &armSerialNumber, const QString &customer,
                     const QString &internalNumber);

signals:

public slots:

  void setControllerSerialNumberColumn(int arg);

  void setArmSerialNumberColumn(int arg);

  void setCustomerNameColumn(int arg);

  void setInternalNumberColumn(int arg);

  void setURLIdColumn(const int &URLIdColumn);

  void setWithHeader(bool arg);

protected:
  void checkDBTables();

private:
  QString m_appData;
  QSqlTableModel *m_table;
};

#endif // MACHINECATALOGUE_H
