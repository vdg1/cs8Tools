#ifndef DIALOGWHATSNEW_H
#define DIALOGWHATSNEW_H

#include <QDialog>

namespace Ui {
class DialogWhatsNew;
}

class DialogWhatsNew : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWhatsNew(QWidget *parent = 0);
    ~DialogWhatsNew();

private:
    Ui::DialogWhatsNew *ui;
};

#endif // DIALOGWHATSNEW_H
