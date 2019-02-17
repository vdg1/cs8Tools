#ifndef CS8SCROLLBAR_H
#define CS8SCROLLBAR_H

#include "cs8logfilefiltermodel.h"
#include "logfilemodel.h"

#include <QPaintEvent>
#include <QPushButton>
#include <QScrollBar>
#include <QTextEdit>

class QToolTip;
class QAbstractItemModel;

namespace cs8Impl {
class cs8PeekView;
}

class cs8Impl::cs8PeekView : public QTextEdit {
  Q_OBJECT
public:
  explicit cs8PeekView(QWidget *parent = 0, QScrollBar *scrollbar = 0);
  void delayHide();
  void show();

protected slots:
  void showContextMenu(const QPoint &p);

protected:
  void leaveEvent(QEvent *event) override;
  void enterEvent(QEvent *event) override;
  void contextMenuEvent(QContextMenuEvent *event) override;

  bool sticky;
  bool blockByContext;

  QTimer *m_timerHideView;
  QPushButton *m_buttonSticky;
  QAction *m_actionGotoLine;
};

class cs8ScrollBar : public QScrollBar {
  Q_OBJECT
public:
  cs8ScrollBar(QWidget *parent = Q_NULLPTR);
  void setModel(cs8LogFileFilterModel *model);
public slots:
  void addHighlight(int row, int totalRow, QBrush brush);
  void resetHighlight();
  void completedHighlight();
  void reverseHighlights(bool reverse);

protected:
  void paintEvent(QPaintEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void leaveEvent(QEvent *event) override;
  void enterEvent(QEvent *event) override;
  QMap<int, QBrush> highLights;
  int m_rowCount;
  bool m_reversed;
  cs8LogFileFilterModel *m_model;
  cs8Impl::cs8PeekView *m_peekView;
};

#endif // CS8SCROLLBAR_H
