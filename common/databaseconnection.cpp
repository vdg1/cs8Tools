#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>

bool checkDBSchemas(QSqlDatabase &db) {
  QSqlQuery q;
  // check backup table
  if (!db.tables().contains(R"(backupData)")) {
      if (!q.exec(QLatin1String("CREATE TABLE `backupData` ("
                                "`id`	INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "`ctrlSerial`	varchar,"
                                "`backupDir`	varchar,"
                                "`backupName`	varchar,"
                                "`createdOn`  varchar,"
                                "`archived`	INTEGER"
                                ");")))
          qDebug() << "Failed to create table backupData:" << q.lastError();
  }

  // check catalogue table
  if (!db.tables().contains("machineCatalogue")) {
    if (!q.exec(QLatin1String("CREATE TABLE `machineCatalogue` ("
                              "`id`	INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "`ctrlSerial`	varchar,"
                              "`armSerial`	varchar,"
                              "`customerName`	varchar,"
                              "`internalNumber`	varchar,"
                              "`catalogueID`	varchar,"
                              "`localyAdded`	INTEGER"
                              ");")))
      qDebug() << "Failed to create table machineCatalogue:" << q.lastError();
  }

  // check log file archive table

  if (!db.tables().contains("tbLogFiles")) {
    if (!q.exec(QLatin1String("CREATE TABLE `tbLogFiles` ("
                              "`id` INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "`hashLogFile` INTEGER, "
                              "`hashSwapFile` INTEGER, "
                              "`spanFrom` varchar,"
                              "`spanTill` varchar,"
                              "`idController` varchar,"
                              "`idArm`	varchar, "
                              "`dlgOpenSwap` INTEGER, "
                              "`dlgIgnoreTimeGap` INTEGER );")))
      qDebug() << "Failed to create table tbLogFiles:" << q.lastError();
  }

  // update log file archive table scheme
  if (!q.exec(QLatin1String("ALTER TABLE tbLogFiles "
                            "ADD lastOpen TIMESTAMP;")))
    qDebug() << "Failed to update table tbLogFiles:" << q.lastError() << " query: " << q.executedQuery();
  if (!q.exec(QLatin1String("ALTER TABLE tbLogFiles "
                            "ADD firstOpen TIMESTAMP;")))
    qDebug() << "Failed to update table tbLogFiles:" << q.lastError() << " query: " << q.executedQuery();

  db.commit();
  return true;
}

bool createDBConnection() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/machineCatalogue.db");
  if (!db.open()) {
    qDebug() << "Couldn't open database:" << db.lastError();
    return false;
  }
  qDebug() << "db opened";
  checkDBSchemas(db);
  return true;
}
