#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "ui_settingsForm.h"

class settingsDialog : public QDialog
{
        Q_OBJECT

    public:
        settingsDialog(QWidget *parent = 0, int page = 0);
        virtual ~settingsDialog();
        void setDefaultDir(const QString & dir);

    protected:
        Ui::SettingsForm ui;

    private:
        QString m_defaultDir;
        QStringList findQmFiles();

    private slots:
        void on_dirButton_clicked();
        void on_okButton_clicked();
        void on_leBackupTemplate_textChanged(const QString);
};

#endif // SETTINGSDIALOG_H
