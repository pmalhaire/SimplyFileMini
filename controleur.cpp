#include "controleur.h"
#include <QDir>
#include <QFileInfo>
#include <QDirIterator>
#include <QtCore>
#include <QDebug>

bool Controleur::listDirs(QString isDir, QStringList &ioDirList)
{
    try{
        QDirIterator dirIt(isDir,
                            QStringList() << "*",
                            QDir::NoSymLinks | QDir::Dirs | QDir::NoDotAndDotDot
                            );
        while (dirIt.hasNext()) {
            dirIt.next();
            if (QFileInfo(dirIt.filePath()).isDir())
            {
                ioDirList.append(dirIt.fileName());
            }
        }
    }catch (QException &e){
        qDebug() << e.what();
        return false;
    }

    return true;
}


bool Controleur::listFiles(QString isDir, QStringList &ioFileList){
    try{
        QDirIterator fileIt(isDir,
                             QStringList() << "*",
                             QDir::NoSymLinks | QDir::Files | QDir::NoDotAndDotDot
                             );
        while (fileIt.hasNext()) {
            fileIt.next();
            if (QFileInfo(fileIt.filePath()).isFile())
            {
                ioFileList.append(fileIt.fileName());
            }
        }
    }catch (QException &e){
        qDebug() << e.what();
        return false;
    }
    return true;
}
