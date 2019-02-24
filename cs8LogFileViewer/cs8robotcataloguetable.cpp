#include "cs8robotcataloguetable.h"
#include <QDebug>
#include <QSqlError>

cs8RobotCatalogueTable::cs8RobotCatalogueTable(QObject *parent) : QSqlTableModel(parent) {
  setTable(R"(tbRobots)");
  qDebug() << "Selecting table for meta information: " << lastError().text();
}

bool cs8RobotCatalogueTable::importCSVFile(QFile *, bool /*clearBeforeImport*/) { return false; }
