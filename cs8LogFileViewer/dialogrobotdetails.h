#ifndef DIALOGROBOTDETAILS_H
#define DIALOGROBOTDETAILS_H

#include <QDialog>

namespace Ui {
class DialogRobotDetails;
}

class DialogRobotDetails : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRobotDetails(QWidget *parent = 0);
    ~DialogRobotDetails();

private:
    Ui::DialogRobotDetails *ui;
};

#endif // DIALOGROBOTDETAILS_H
