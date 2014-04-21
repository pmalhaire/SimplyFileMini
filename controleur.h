#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QStringList>
#include <QDir>

namespace Controleur
{

    //list files in a dir (excluding dirs)
    //QStringList must be deleted by caller
    QStringList * listFiles(QString isDir);
    //list dir in a dir (excluding files)
    //QStringList must be deleted by caller
    QStringList * listDirs(QString isDir);
}

#endif // CONTROLEUR_H
