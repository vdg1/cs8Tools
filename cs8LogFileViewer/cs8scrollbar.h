#ifndef CS8SCROLLBAR_H
#define CS8SCROLLBAR_H

#include <QPaintEvent>
#include <QScrollBar>

class QToolTip;
class QAbstractItemModel;

class cs8ScrollBar : public QScrollBar {
  Q_OBJECT
public:
  cs8ScrollBar(QWidget *parent = Q_NULLPTR);
  void setModel(QAbstractItemModel *model);
public slots:
  void addHighlight(int row, int totalRow, QBrush brush);
  void resetHighlight();
  void completedHighlight();
  void reverseHighlights(bool reverse);

protected:
  void paintEvent(QPaintEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  QMap<int, QBrush> highLights;
  int m_rowCount;
  bool m_reversed;
  QAbstractItemModel *m_model;
};

#endif // CS8SCROLLBAR_H
