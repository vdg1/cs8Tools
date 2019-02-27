#ifndef CS8LOGFILEANNOTATIONS_H
#define CS8LOGFILEANNOTATIONS_H

#include <QSqlTableModel>

class cs8LogFileAnnotations : public QSqlQueryModel {
  Q_OBJECT
public:
  explicit cs8LogFileAnnotations(QObject *parent = 0);
  void setHash(qint64 hash);
  void addAnnotation(const QString &text, int level, int start, int end);

protected:
  qint64 m_hash;
  void updateQuery();
};

#endif // CS8LOGFILEANNOTATIONS_H
