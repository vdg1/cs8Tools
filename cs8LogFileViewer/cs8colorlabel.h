#ifndef CS8COLORLABEL_H
#define CS8COLORLABEL_H

#include <QLineEdit>

class cs8ColorLabel : public QLineEdit
{
    Q_OBJECT

    Q_PROPERTY( QColor color READ color WRITE setColor NOTIFY colorChanged USER true)

public:
    explicit cs8ColorLabel(QWidget *parent = 0);
    QColor color() const;
    
signals:
    void clicked();
    void colorChanged();
    
public slots:
    void setColor(const QColor & color);

protected slots:
    void slotClicked();

protected:
    QColor m_color;
    void mousePressEvent ( QMouseEvent * event );
    
};

#endif // CS8COLORLABEL_H
