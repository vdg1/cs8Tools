#include "cs8scrollbar.h"

#include <QDebug>
#include <QPainter>
#include <QStyleOptionSlider>
#include <QToolTip>

cs8ScrollBar::cs8ScrollBar(QWidget *parent) : QScrollBar(parent), m_rowCount(0), m_reversed(false), m_model(0) {
  setMouseTracking(true);
}

void cs8ScrollBar::setModel(QAbstractItemModel *model) { m_model = model; }

void cs8ScrollBar::addHighlight(int row, int totalRow, QBrush brush) {
  highLights[row] = brush;
  m_rowCount = totalRow;
}

void cs8ScrollBar::resetHighlight() {
  highLights.clear();
  update();
}

void cs8ScrollBar::completedHighlight() { update(); }

void cs8ScrollBar::reverseHighlights(bool reverse) {
  m_reversed = reverse;
  update();
}

void cs8ScrollBar::paintEvent(QPaintEvent *event) {
  QScrollBar::paintEvent(event);

  QPainter p(this);
  QStyleOptionSlider opt;

  initStyleOption(&opt);

  QRect gr = style()->subControlRect(QStyle::CC_ScrollBar, &opt, QStyle::SC_ScrollBarGroove, this);
  QRect sr = style()->subControlRect(QStyle::CC_ScrollBar, &opt, QStyle::SC_ScrollBarSlider, this);
  sr.adjust(1, 0, -1, 0);
  p.setClipRegion(QRegion(gr) - QRegion(sr), Qt::IntersectClip);
  int x, y, w, h;
  gr.getRect(&x, &y, &w, &h);
  QColor c;
  QMapIterator<int, QBrush> i(highLights);
  int pos = 0;
  auto posFract = 0.0;

  while (i.hasNext()) {
    i.next();
    posFract = static_cast<double>(i.key()) / m_rowCount;
    if (!m_reversed)
      pos = static_cast<double>(posFract) * h;
    else
      pos = static_cast<double>((1 - posFract)) * h;
    c = i.value().color();
    c.setAlpha(200);

    p.setPen(QPen(c, 1, Qt::SolidLine));
    // p.drawRect(x,y,w,h-1);
    p.drawLine(0, pos + y, w, pos + y);
    // qDebug() << i.key() << ": " << i.value() << endl;
  }
}

void cs8ScrollBar::mouseMoveEvent(QMouseEvent *event) {
  QScrollBar::mouseMoveEvent(event);
  qDebug() << minimum() << maximum() << event->pos() << height();
  if (m_model != Q_NULLPTR) {
    double row = (event->pos().y() - 17);
    row /= (height() - 17 * 2);
    row = row < 0 ? 0 : row > 1 ? 1 : row;
    row *= m_model->rowCount();
    row = (int)row;
    QToolTip::showText(mapToGlobal(event->pos()), QString("Row: %3").arg(row));
  }
}
