#include "ftpthread.h"

void ftpThread::run()
{
}

void ftpThread::setFtpConnection(QFtp* ftp_)
{
    ftp=ftp_;
}

void ftpThread::setDestinationDir(QDir dir_)
{
    destinationDir=dir_;
}
