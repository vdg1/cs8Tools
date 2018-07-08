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

#ifndef ZIPPER_H
#define ZIPPER_H

#include <QMainWindow>
#include <zip/quazip.h>
#include <zip/quazipfile.h>

class QDir;
class QString;
class QStringList;

class zipper : public  QWidget, QuaZip
{
        Q_OBJECT

    public:
        zipper();
        ~zipper();
        void compressDir(const QDir &dirInfo, const QString &fileName, bool deleteFiles = false);

    protected:
        QStringList getFileList(const QDir &dirInfo);
        QStringList getDirList(const QDir &dirInfo);
        bool deleteDir(QString dirName);


    private:

    signals:
        void compressingFile(const QString fileName, int index, int count);
        void completed(bool result);
};

#endif // ZIPPER_H
