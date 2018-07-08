#include <QFtp>
#include <QtXml>

#include "ftpserialthread.h"


ftpSerialThread::ftpSerialThread(QObject *parent)
     : QThread(parent), quit(false)
 {
 	ftp = new QFtp(parent);
 }
 
ftpSerialThread::~ftpSerialThread()
 {
     quit = true;
     cond.wakeOne();
     wait();
 }

void ftpSerialThread::requestSerialNumber(const QString &hostName_, const QString &userName_, const QString &password_)
 {
   //  QMutexLocker locker(&mutex);
     this->hostName = hostName_;
     this->userName = userName_;
     this->password = password_;
     start();
 }


void ftpSerialThread::run()
{
    // mutex.lock();
     QString _hostName = hostName;
     QString _userName = userName;
     QString _password = password;
   //  mutex.unlock();
    

     connect( ftp, SIGNAL( commandFinished( int, bool ) ),
           this, SLOT( ftpCommandFinished( int, bool ) ) ,Qt::QueuedConnection);

	  ftp->connectToHost( _hostName );
	  ftp->login( _userName, _password );
	  exec();
	  /*
	QMutexLocker locker(&mutex);

         QString fortune=baseDir;
         
         emit finished(fortune);

         cond.wait(&mutex);
         */
}
       

bool ftpSerialThread::retrieveSerialNumber()
{
  // load /usr/configs/arm.cfx
  nConfigCmdID = ftp->get ( "/usr/configs/arm.cfx", 0 );

  while ( ftp->currentId() != 0 );
   // qApp->processEvents();

  if ( nConfigCmdID == -1 )
    {
      // loading /usr/configs/arm.cfx failed
      // try to load /sys/configs/options.cfx

      nConfigCmdID = ftp->get ( "/sys/configs/options.cfx", 0 );
      while ( ftp->currentId() != 0 );
        //qApp->processEvents();

      if ( nConfigCmdID == -1 )
        {
          // loading /sys/configs/options.cfx failed
          // set current IP address as base directory
          baseDir = "";//ftpServerLineEdit->lineEdit() ->text();
        }
      else
        {
          QDomDocument doc;
          doc.setContent( configBuffer );
          baseDir = orderNumber( doc.documentElement() );
        }
    }

  else
    {
      QDomDocument doc;
      doc.setContent( configBuffer );
      baseDir = orderNumber( doc.documentElement() );
    }
}


QString ftpSerialThread::orderNumber( const QDomElement & element )
{
  for ( int i = 0; i < element.elementsByTagName( "String" ).count(); i++ ){
      QDomNode node = element.elementsByTagName( "String" ).at( i );
      if ( node.toElement().attribute( "name" ) == "orderNumber" )
        return node.toElement().attribute( "value" );
    }
  return QString( "" );//ftpServerLineEdit->lineEdit()->text();
}



void ftpSerialThread::ftpCommandFinished( int, bool error )
{
  if ( ftp->currentCommand() == QFtp::Get )
    {
      if ( !error )
        configBuffer = ftp->readAll();
      else
        nConfigCmdID = -1;
    }
   if (ftp->currentCommand() == QFtp::Login)
   {
   	if (!error)
   		retrieveSerialNumber();
  	}
}
