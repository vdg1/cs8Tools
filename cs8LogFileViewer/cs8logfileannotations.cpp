#include "cs8logfileannotations.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

cs8LogFileAnnotations::cs8LogFileAnnotations(QObject *parent) : QSqlQueryModel(parent), m_hash(0) {}

void cs8LogFileAnnotations::updateQuery() {
  QSqlQuery query;
  query.prepare("SELECT * from tbLogAnnotations WHERE hashLogFile = :hash");
  query.bindValue(":hash", m_hash);
  query.exec();
  setQuery(query);
  qDebug() << __FUNCTION__ << ":" << query.executedQuery() << ":" << lastError() << ":" << query.boundValues();
}

void cs8LogFileAnnotations::setHash(qint64 hash) {
  m_hash = hash;
  updateQuery();
}

void cs8LogFileAnnotations::addAnnotation(const QString &text, int level, int start, int end) {
  QSqlQuery query;
  query.prepare("INSERT INTO tbLogAnnotations (hashLogFile, rowStart, rowEnd, text, level) "
                "VALUES (:hash, :rowStart, :rowEnd, :text, :level)");
  query.bindValue(":hash", m_hash);
  query.bindValue(":rowStart", start);
  query.bindValue(":rowEnd", end);
  query.bindValue(":text", text);
  query.bindValue(":level", level);
  query.exec();
  qDebug() << __FUNCTION__ << ":" << query.executedQuery() << ":" << lastError() << ":" << query.boundValues();
  updateQuery();
}
