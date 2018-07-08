#ifndef WIZARDCREATEBACKUP_H
#define WIZARDCREATEBACKUP_H

#include <QtWidgets/QWizard>

namespace Ui {
class WizardCreateBackup;
}

class WizardCreateBackup : public QWizard
{
        Q_OBJECT

    public:
        explicit WizardCreateBackup(QWidget *parent = 0);
        ~WizardCreateBackup();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::WizardCreateBackup *ui;
};

#endif // WIZARDCREATEBACKUP_H
