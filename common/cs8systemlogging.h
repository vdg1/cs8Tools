#ifndef CS8SYSTEMLOGGING_H
#define CS8SYSTEMLOGGING_H

#define LOGSIZE 1024 * 100 // log size in bytes
#define LOGFILES 5

#include <QDate>
#include <QDebug>
#include <QObject>
#include <QStandardPaths>
#include <QString>
#include <QTime>

namespace LOGUTILS {
const QString logFolderName = R"(logs)";

bool initLogging();
void myMessageHandler(QtMsgType type, const QMessageLogContext &,
                      const QString &msg);
} // namespace LOGUTILS
#endif // CS8SYSTEMLOGGING_H
