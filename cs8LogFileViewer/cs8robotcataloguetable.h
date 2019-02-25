#ifndef CS8ROBOTCATALOGUETABLE_H
#define CS8ROBOTCATALOGUETABLE_H

#include <QSqlTableModel>

class QFile;

class cs8RobotCatalogueTable : public QSqlTableModel {
    Q_OBJECT
public:
    explicit cs8RobotCatalogueTable(QObject *parent = 0);
    bool importCSVFile(QFile * /*file*/, bool = false);
};

#endif // CS8ROBOTCATALOGUETABLE_H
