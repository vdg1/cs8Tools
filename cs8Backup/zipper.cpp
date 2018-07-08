/**************************************************************************
*   Copyright (C) 2006 by Volker Drewer-Gutland                           *
*   volker.drewer@gmx.de                                                  *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#include "zipper.h"

#include <zip/quazipfile.h>
#include <QtCore>
#include <QtGui>

zipper::zipper()
{
    //ctor
}

zipper::~zipper()
{
    //dtor
}

void zipper::compressDir(const QDir &dirInfo, const QString &outFileName, bool deleteFiles)
{
    QStringList fileList = getFileList(dirInfo);


    QuaZip zip(outFileName);
    if (!zip.open(QuaZip::mdCreate))
    {
        qWarning("testCreate(): zip.open(): %d", zip.getZipError());
        emit(completed(false));
        return;
    }
    QFile inFile;
    QuaZipFile outFile(&zip);

    int idx = 1;
    foreach(QString fileName, fileList)
    {
        emit(compressingFile(fileName, idx++, fileList.count()));
        qApp->processEvents();
        inFile.setFileName(dirInfo.absolutePath() + "/" + fileName);
        if (!inFile.open(QIODevice::ReadOnly))
        {
            qWarning("testCreate(): inFile.open(): %s", inFile.errorString().toLocal8Bit().constData());
            emit(completed(false));
            return;
        }
        if (!outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(fileName, inFile.fileName())))
        {
            qWarning("testCreate(): outFile.open(): %d", outFile.getZipError());
            emit(completed(false));
            return;
        }
        QByteArray data = inFile.readAll();
        if (outFile.write(data) != inFile.size())
        {
            emit(completed(false));
            return;
        };
        //while (inFile.getChar(&c)&&outFile.putChar(c));
        if (outFile.getZipError() != UNZ_OK)
        {
            qWarning("testCreate(): outFile.putChar(): %d", outFile.getZipError());
            emit(completed(false));
            return;
        }
        outFile.close();
        if (outFile.getZipError() != UNZ_OK)
        {
            qWarning("testCreate(): outFile.close(): %d", outFile.getZipError());
            emit(completed(false));
            return;
        }
        inFile.close();
    }
    zip.close();
    if (zip.getZipError() != 0)
    {
        qWarning("testCreate(): zip.close(): %d", zip.getZipError());
        emit(completed(false));
        return;
    }
    if (deleteFiles)
    {
        deleteDir(dirInfo.absolutePath());
    }
    emit(completed(true));
}

QStringList zipper::getFileList(const QDir &dirInfo)
{
    QStringList dirList;
    QStringList fileList;
    dirList.append(dirInfo.absolutePath());
    QString currentSubDir = "/";
    while (dirList.count() > 0)
    {
        QDir dir(dirList.at(0)/*+currentSubDir*/);
        dirList.removeFirst();
        QFileInfoList infoList = dir.entryInfoList();
        for (int i = 2; i < infoList.count(); i++)
        {
            QFileInfo fileInfo = infoList.at(i);
            if (fileInfo.isFile())
                fileList.append(fileInfo.absoluteFilePath().remove(0, dirInfo.absolutePath().length() + 1));
            if (fileInfo.isDir())
                dirList.append(fileInfo.absoluteFilePath());
        }
    }
    return fileList;
}


QStringList zipper::getDirList(const QDir &dirInfo)
{
    QStringList dirList;
    QStringList dirs;
    dirList.append(dirInfo.absolutePath());
    QString currentSubDir = "/";
    while (dirList.count() > 0)
    {
        QDir dir(dirList.at(0)/*+currentSubDir*/);
        dirList.removeFirst();

        QFileInfoList infoList = dir.entryInfoList();
        for (int i = 2; i < infoList.count(); i++)
        {
            QFileInfo fileInfo = infoList.at(i);
            if (fileInfo.isDir())
                dirs.append(fileInfo.absoluteFilePath().remove(0, dirInfo.absolutePath().length()));
            if (fileInfo.isDir())
                dirList.append(fileInfo.absoluteFilePath());
        }
    }
    return dirs;
}
bool zipper::deleteDir(QString dirName)
{

    QDir dir;
    foreach(QString fileName, getFileList(QDir(dirName)))
    dir.remove(dirName + "/" + fileName);

    foreach(QString dirs, getDirList(QDir(dirName)))
    dir.rmpath(dirName + "/" + dirs);
    return true;
}

