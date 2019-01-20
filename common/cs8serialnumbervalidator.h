#ifndef CS8SERIALNUMBERVALIDATOR_H
#define CS8SERIALNUMBERVALIDATOR_H

#include <QLineEdit>
#include <QObject>
#include <QRegExpValidator>

class cs8SerialNumberValidator : public QValidator {
public:
  explicit cs8SerialNumberValidator(QObject *parent = nullptr);

  // void fixup(QString &input) const override;
  QValidator::State validate(QString &input, int &pos) const override;

protected:
  QLineEdit *m_editor;
};
// QRegExp("^F/{0,1}\\d{2}/\\S{6,7}/C/\\d{2,3}$")
#endif // CS8SERIALNUMBERVALIDATOR_H
