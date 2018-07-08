#include <QDomDocument>
#include <QFile>

/*
   void setVersion()
   {
    /*
    QFile file(":/files/svn-info.xml");
    QDomDocument doc;
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QString version = APP_VERSION;
    version += "r" + doc.elementsByTagName("info").at(0).toElement().elementsByTagName("entry").at(0).toElement().attribute("revision");

    QFile file(":/files/version.txt");
    if (!file.open (QIODevice::ReadOnly))
        return;
    QString revision=file.readLine ();
    file.close();
    QString version = APP_VERSION;
    version += "r" + revision;
    QCoreApplication::setApplicationVersion(version);
   }
 */
