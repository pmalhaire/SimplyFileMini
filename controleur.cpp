#include "controleur.h"
#include <QDir>
#include <QFileInfo>
#include <QDirIterator>
#include <QtCore>

QStringList * Controleur::listDirs(QString isDir)
{

    //returns a pointer best would be a reference
    QStringList * pResult = new QStringList();
    QDirIterator dirIt(isDir,
                       QStringList() << "*",
                       QDir::NoSymLinks | QDir::Dirs | QDir::NoDotAndDotDot
                       );
    if(!dirIt.hasNext())
    {
        delete pResult;
        pResult=NULL;
        return NULL;
    }

    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isDir())
        {
            pResult->append(dirIt.fileName());
        }
    }
    return pResult;
}


QStringList * Controleur::listFiles(QString isDir){
    QStringList * pResult = new QStringList();
    QDirIterator fileIt(isDir,
                        QStringList() << "*",
                        QDir::NoSymLinks | QDir::Files | QDir::NoDotAndDotDot
                        );
    if(!fileIt.hasNext())
    {
        delete pResult;
        pResult=NULL;
        return NULL;
    }
    while (fileIt.hasNext()) {
        fileIt.next();
        if (QFileInfo(fileIt.filePath()).isFile())
        {
            pResult->append(fileIt.fileName());
        }
    }
    return pResult;
}
