#include "selectbackupfolderdialog.h"
#include "QDir"
#include "QDebug"
#include "QDateTime"

selectBackupFolderDialog::selectBackupFolderDialog(QWidget *parent, const QString &controller, const QStringList list)
    : QDialog(parent)
{
    ui.setupUi(this);
    ui.label->setText(ui.label->text().arg(controller));

    ui.listWidget->setRowCount(list.count());
    QTableWidgetItem *newItem;
    int row = 0;
    foreach(QString item, list)
    {
        QDir dir(item);

        QStringList backups = dir.entryList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Name);
        QString dateText;
        if (backups.count() > 0)
        {
            int pos=0;
            QDateTime date;
            QRegExp rx("[\\d]{8}-[\\d]{4}");
            QString dateString;
            do
            {
                pos = rx.indexIn(backups.last());
                if (pos > -1)
                    dateString = rx.cap(0);

                date = QDateTime::fromString(dateString, "yyyyMMdd-hhmm");
                if (date.date().isValid())
                    dateText = date.toString(Qt::LocaleDate);
                else
                    dateText = "Unknown";
                backups.removeLast();
            } while (pos<0 && backups.count()>0);
            if (backups.count()==0 && !date.isValid())
                dateText = "Unknown";
        }
        else
            dateText = "No Backup in folder";
        newItem = new QTableWidgetItem(dateText);
        ui.listWidget->setItem(row, 1, newItem);
        newItem = new QTableWidgetItem(item);
        ui.listWidget->setItem(row++, 0, newItem);
    }
    ui.listWidget->sortItems(1, Qt::DescendingOrder);
    ui.listWidget->setCurrentCell(0, 0);

    ui.listWidget->resizeColumnsToContents();

}

selectBackupFolderDialog::~selectBackupFolderDialog()
{

}

QString selectBackupFolderDialog::selectedBackup()
{
    return ui.listWidget->currentItem()->text();
}
