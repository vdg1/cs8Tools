#ifndef LOGFILEDETAILEDINFORMATIONFORM_H
#define LOGFILEDETAILEDINFORMATIONFORM_H

#include <QWidget>

namespace Ui {
    class logFileDetailedInformationForm;
}
class QSqlTableModel;
class QDataWidgetMapper;
class cs8MetaInformationModel;

class logFileDetailedInformationForm : public QWidget
{
    Q_OBJECT

public:
    explicit logFileDetailedInformationForm(QWidget *parent = 0);
    ~logFileDetailedInformationForm();
    void setModel(cs8MetaInformationModel *model);
    void selectRow(int row);

protected slots:
    void selectRecord(int row);

private:
    Ui::logFileDetailedInformationForm *ui;
    QDataWidgetMapper* m_mapper ;
};

#endif // LOGFILEDETAILEDINFORMATIONFORM_H
