#ifndef BACKUPSTORAGE_H
#define BACKUPSTORAGE_H

#include <QObject>
#include <QFile>

class backupStorage : public QObject
{
        Q_OBJECT
    public:
        explicit backupStorage(QObject *parent = 0);
        void setStorageBasePath(const QString &path);
        void setAppDataPath(const QString &path);
        QStringList backupSets(QString &base);
        void updateStorage(bool async = false);
        void addToStorage(const QString &newPath);

        void cleanupResultList(QStringList resultist);
    protected:
        QString m_storageBasePath;
        QString m_storageFileName;
        QString m_appDataDir;
        QStringList localCatalogue(const QString &dataPath, const QString &storageBasePath, const QString &base);
        static void update(const QString &basePath, const QString &path);
        static void updateRecursive(QStringList &resultList,  const QString &basePath, const QString &path);

};

#endif // BACKUPSTORAGE_H
