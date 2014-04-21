#include "controleur.h"
#include <QDir>
#include <QFileInfo>
#include <QDirIterator>
#include <QtCore>

QStringList * Controleur::listDirs(QString sDir)
{

    //   # chdir() to user requested dir (root + "/" + dir)
    // Dir.chdir(File.expand_path(path).untaint);
    QStringList * result = new QStringList();
    QDirIterator dirIt(sDir,
                       QStringList() << "*",
                       QDir::NoSymLinks | QDir::Dirs | QDir::NoDotAndDotDot
                       );
    if(!dirIt.hasNext())
    {
        delete result;
        result=NULL;
        return NULL;
    }

    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isDir())
        {
            result->append(dirIt.fileName());
        }
    }
    return result;
}


QStringList * Controleur::listFiles(QString sDir){
    QStringList * result = new QStringList();
    QDirIterator fileIt(sDir,
                        QStringList() << "*",
                        QDir::NoSymLinks | QDir::Files | QDir::NoDotAndDotDot
                        );
    if(!fileIt.hasNext())
    {
        delete result;
        result=NULL;
        return NULL;
    }
    while (fileIt.hasNext()) {
        fileIt.next();
        if (QFileInfo(fileIt.filePath()).isFile())
        {
            result->append(fileIt.fileName());
        }
    }
    return result;
}
