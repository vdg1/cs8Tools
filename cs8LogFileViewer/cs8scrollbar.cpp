#include "cs8scrollbar.h"

#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QPainter>
#include <QStyleOptionSlider>
#include <QToolTip>

cs8ScrollBar::cs8ScrollBar(QWidget *parent) : QScrollBar(parent), m_rowCount(0), m_reversed(false), m_model(0) {
  setMouseTracking(true);
  m_peekView = new cs8Impl::cs8PeekView(parent, this);
}

void cs8ScrollBar::setModel(cs8LogFileFilterModel *model) { m_model = model; }

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

  while (i.hasNext()) {
    i.next();
    auto posFract = static_cast<double>(i.key()) / m_rowCount;
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

  if (m_model != Q_NULLPTR) {
    double row = (event->pos().y() - 17);
    row /= (height() - 17 * 2);
    row = row < 0 ? 0 : row > 1 ? 1 : row;
    row *= m_model->rowCount();
    row = (int)row;
    QToolTip::showText(mapToGlobal(event->pos()), QString("Row: %3").arg(row));

    QPoint p(qobject_cast<QWidget *>(m_peekView->parent())->width() - m_peekView->width() - this->width() - 10,
             qMin(qMax(0, event->pos().ry() - m_peekView->height() / 2), this->height() - m_peekView->height()));
    m_peekView->move(p);
    // m_peekView->setText(qobject_cast<logFileModel *>(m_model->sourceModel())->logMessage(row));
    // m_peekView->setText(qobject_cast<logFileModel *>(m_model->sourceModel())->getLines(row - 7, 15));
    m_peekView->setText(m_model->getLines(row - 7, 15));
  }
}

void cs8ScrollBar::leaveEvent(QEvent *event) {
  QScrollBar::leaveEvent(event);
  m_peekView->delayHide();
}

void cs8ScrollBar::enterEvent(QEvent *event) {
  QScrollBar::enterEvent(event);
  m_peekView->show();
}

void cs8ScrollBar::scrollViewToRow(int lineNumber) { emit scrollToRow(lineNumber); }

cs8Impl::cs8PeekView::cs8PeekView(QWidget *parent, cs8ScrollBar *scrollbar) : QTextEdit(parent), sticky(false) {

  setContextMenuPolicy(Qt::CustomContextMenu);
  connect(this, &QTextEdit::customContextMenuRequested, this, &cs8Impl::cs8PeekView::showContextMenu);

  m_actionGotoLine = new QAction(this);
  m_actionGotoLine->setText(tr("Goto line"));
  connect(m_actionGotoLine, &QAction::triggered, this, [=]() {
    cs8ScrollBar *sb = scrollbar;
    sb->scrollViewToRow(m_actionGotoLine->data().toInt() - 1);
  });

  hide();
  setReadOnly(true);
  setFontPointSize(10);
  setLineWrapMode(QTextEdit::NoWrap);
  setFontFamily("courier");
  QFontMetrics m(font());
  resize(500, m.height() * 15);

  // setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  m_buttonSticky = new QPushButton(this);
  m_buttonSticky->setCheckable(true);
  m_buttonSticky->resize(16, 16);
  m_buttonSticky->move(width() - m_buttonSticky->width(), 0);
  m_buttonSticky->setIcon(QIcon(":/icons/32x32/32x32/actions/layer-visible-off.png"));
  connect(m_buttonSticky, &QPushButton::clicked, this, [this]() {
    sticky = !sticky;
    if (sticky) {
      m_buttonSticky->setIcon(QIcon(":/icons/32x32/32x32/actions/layer-visible-on.png"));
      m_timerHideView->stop();
    } else {
      m_buttonSticky->setIcon(QIcon(":/icons/32x32/32x32/actions/layer-visible-off.png"));
      hide();
    }
  });

  m_timerHideView = new QTimer(this);
  m_timerHideView->setSingleShot(true);
  m_timerHideView->setInterval(1000);
  connect(m_timerHideView, &QTimer::timeout, this, [this]() {
    if (!sticky)
      hide();
  });
}

void cs8Impl::cs8PeekView::delayHide() { m_timerHideView->start(); }

void cs8Impl::cs8PeekView::leaveEvent(QEvent *event) {
  QTextEdit::leaveEvent(event);
  if (!blockByContext)
    delayHide();
  blockByContext = false;
}

void cs8Impl::cs8PeekView::enterEvent(QEvent *event) {
  QTextEdit::enterEvent(event);
  m_timerHideView->stop();
}

void cs8Impl::cs8PeekView::contextMenuEvent(QContextMenuEvent *event) {
  QTextEdit::contextMenuEvent(event);
  m_timerHideView->stop();
  blockByContext = true;
}

void cs8Impl::cs8PeekView::show() {
  QTextEdit::show();
  m_timerHideView->stop();
}

void cs8Impl::cs8PeekView::showContextMenu(const QPoint &p) {
  QMenu *menu = createStandardContextMenu();

  QTextCursor tc = cursorForPosition(p);
  tc.select(QTextCursor::LineUnderCursor);
  QString strWord = tc.selectedText();
  int lineNumber = strWord.split(":").at(0).toInt();
  m_actionGotoLine->setData(lineNumber);
  m_actionGotoLine->setText(tr("Goto line %1").arg(lineNumber));
  menu->addAction(m_actionGotoLine);
  menu->exec(mapToGlobal(p));
  delete menu;
}
