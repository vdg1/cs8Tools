#include "cs8serialnumbervalidator.h"
#include <QDebug>
cs8SerialNumberValidator::cs8SerialNumberValidator(QObject *parent) : QValidator(parent), m_editor(0) {
  if (qobject_cast<QLineEdit *>(parent) != nullptr) {
    m_editor = qobject_cast<QLineEdit *>(parent);
    m_editor->setValidator(this);
    int pos = 0;
    QString s = m_editor->text();
    validate(s, pos);
  }
}

// void cs8SerialNumberValidator::fixup(QString &input) const {}

QValidator::State cs8SerialNumberValidator::validate(QString &input, int &pos) const {
  QValidator::State state = Intermediate;
  QRegExp rx("^(F)([/]{0,1}){0,1}(\\d{2}){0,1}");
  bool legacyFormat = false;
  rx.indexIn(input);
  // qDebug() << rx.capturedTexts();
  if (rx.cap(1).isEmpty())
    state = Invalid;

  if (rx.cap(2).isEmpty())
    legacyFormat = true;

  if (legacyFormat)
    rx.setPattern("^F\\d{2}/\\S{6}/C/\\d{2}$");
  else
    rx.setPattern("^F/\\d{2}/\\d{7}/C/\\d{3}$");

  int p = rx.indexIn(input);
  qDebug() << rx.capturedTexts();
  if (p != -1) {

    state = Acceptable;
  }
  if (m_editor != nullptr)
    switch (state) {
    case QValidator::Invalid:
      m_editor->setStyleSheet("QLineEdit{border: 2px solid red}");
      break;

    case QValidator::Intermediate:
      m_editor->setStyleSheet("QLineEdit{border: 2px solid yellow}");
      break;

    case QValidator::Acceptable:
      m_editor->setStyleSheet("QLineEdit{border: 2px solid green}");
      break;
    }

  return state;
}
