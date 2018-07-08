#ifndef FTPTHREAD_H
#define FTPTHREAD_H

#include <QThread>
#include <QDir>

class QFtp;

class ftpThread : public QThread
  {
    public:
      void run();
      void setFtpConnection( QFtp* ftp_ );
      void setDestinationDir( QDir dir_ );

    protected:
      QFtp *ftp;
      QDir destinationDir;
    private:
  };

#endif // FTPTHREAD_H
