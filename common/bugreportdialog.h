#ifndef BUGREPORTDIALOG_H
#define BUGREPORTDIALOG_H


#include <QtWidgets/QDialog>

namespace Ui {
class bugReportDialog;
}

class bugReportDialog : public QDialog
{
        Q_OBJECT

    public:
        explicit bugReportDialog(QWidget *parent = 0);
        ~bugReportDialog();
        void setAttachment(const QString & url);

    protected:
        void changeEvent(QEvent *e);

    private slots:
        void on_pushButton_2_clicked();

    private:
        Ui::bugReportDialog *ui;
        QString m_recipient;
        QString m_attachUrl;
};

#endif // BUGREPORTDIALOG_H
