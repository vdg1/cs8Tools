#ifndef CS8SCROLLBAR_H
#define CS8SCROLLBAR_H

#include <QScrollBar>
#include <QPaintEvent>

class cs8ScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    cs8ScrollBar ( QWidget * parent = Q_NULLPTR );
public slots:
    void addHighlight(int row, int totalRow, QBrush brush);
    void resetHighlight();
    void completedHighlight();
    void reverseHighlights(bool reverse);

protected:
    void paintEvent(QPaintEvent * event);
    QMap<int,QBrush> highLights;
    int m_rowCount;
    bool m_reversed;
};

#endif // CS8SCROLLBAR_H
