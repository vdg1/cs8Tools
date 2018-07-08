#ifndef CS8LOGFILEDATA_H
#define CS8LOGFILEDATA_H

#include "logfiledata.h"
#include <QDateTime>
#include <QFile>
#include <QObject>

class cs8LogFileData : public QObject {
    Q_OBJECT
  public:
    explicit cs8LogFileData(QObject* parent = 0);

    uint hashLogFile() const;

    QStringList rawData() const;

    QString dateFormat() const;

    QDateTime startDate() const;

    QDateTime endDate() const;
    enum FileType { CS8Legacy, CS8, CS9 };
    Q_ENUM(FileType)

    enum MessageLevel { Anything, Information, Warning, Error, Undefined };
    Q_ENUM(MessageLevel)

    FileType fileType() const;
    static QStringList levelNames;

  signals:

  public slots:
    void load(QFile* file);

  private:
    QString guessDateFormat(const QStringList& lines);

  protected:
    uint m_hashLogFile;
    QStringList m_rawData;
    logFileData m_data;
    QString m_dateFormat;
    QDateTime m_startDate, m_endDate;
    cs8LogFileData::FileType m_fileType;
    void process();
    void identifyTimeStamps();
    void identifyFileContent();
};

#endif // CS8LOGFILEDATA_H
