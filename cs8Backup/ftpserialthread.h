#ifndef FTPSERIALTHREAD_H
#define FTPSERIALTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDir>
#include <QFtp>
#include <QtXml>


class ftpSerialThread : public QThread
  {
      Q_OBJECT

    public:
      ftpSerialThread(QObject *parent = 0);
      ~ftpSerialThread();
      void run();
      void requestSerialNumber(const QString &hostName_, const QString &userName_, const QString &password_);

    protected:
      QFtp *ftp;
      QDir destinationDir;
      int nConfigCmdID;
      QString configBuffer;
	  QMutex mutex;
      QWaitCondition cond;
      bool quit;
      QString hostName;
      QString userName;
      QString password;
      QString baseDir;
     
      bool retrieveSerialNumber();
      QString getSerialNumber();
      QString orderNumber( const QDomElement &element );

   protected slots:
      void ftpCommandFinished(int,bool);
      
    signals:
      void finished(const QString &baseDir);
  };

#endif // FTPTHREAD_H
