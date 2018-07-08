#ifndef DOWNLOADDIRDIALOG_H
#define DOWNLOADDIRDIALOG_H

#include <QDialog>
#include "ui_downloaddirdialog.h"

class downloadDirDialog : public QDialog
{
        Q_OBJECT

    public:
        downloadDirDialog(QWidget *parent = 0);
        downloadDirDialog(QWidget *parent, const QString &baseDir,
                          const QString &downloadDir);

        ~downloadDirDialog();

        QString baseDir();
        QString downloadDir()
        {
            return m_downloadDir;
        }
        bool modified()
        {
            return m_modified;
        }


    protected slots:
        void on_toolButtonUserDefined_clicked();
        void on_lineEditUserDefined_textChanged(const QString &text);

    private:
        Ui::downloadDirDialogClass ui;
        bool m_mode;
        bool m_modified;
        QString m_baseDir;
        QString m_downloadDir;
};

#endif // DOWNLOADDIRDIALOG_H
