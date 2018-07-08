#ifndef GETSERIALNUMBERDIALOG_H
#define GETSERIALNUMBERDIALOG_H

#include <QDialog>
#include "ui_getserialnumberdialog.h"

class QRegExpValidator;

class getSerialNumberDialog : public QDialog
{
        Q_OBJECT

    public:
        getSerialNumberDialog(QWidget *parent = 0);
        ~getSerialNumberDialog();

        static QString getText(QWidget *parent, bool *ok = 0);
        QString text()
        {
            return ui.lineEdit->text();
        };
        bool isValid();
    private:
        Ui::getSerialNumberDialogClass ui;
        QRegExpValidator *validator;

    protected slots:
        void on_lineEdit_textChanged(const QString &);
};

#endif // GETSERIALNUMBERDIALOG_H
