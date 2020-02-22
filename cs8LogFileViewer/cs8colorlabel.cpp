#include "cs8colorlabel.h"
#include <QColorDialog>

cs8ColorLabel::cs8ColorLabel(QWidget *parent) : QLineEdit(parent) {
  setReadOnly(true);
  connect(this, SIGNAL(clicked()), this, SLOT(slotClicked()));
}

QColor cs8ColorLabel::color() const { return m_color; }

void cs8ColorLabel::mousePressEvent(QMouseEvent *event) { emit clicked(); }

void cs8ColorLabel::setColor(const QColor &col) {
  if (m_color == col)
    return;

  m_color = col;
  setText(m_color.name());
  QPalette pal = palette();
  pal.setColor(foregroundRole(), col);
  setPalette(pal);
  emit colorChanged();
}

void cs8ColorLabel::slotClicked() {
  QColorDialog dialog;
  dialog.setCurrentColor(m_color);
  if (dialog.exec() == QDialog::Accepted) {
    setColor(dialog.currentColor());
  }
}
