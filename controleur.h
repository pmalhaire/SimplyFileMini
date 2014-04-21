#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QStringList>
#include <QDir>

namespace Controleur
{

    //list files in a dir (excluding dirs)
    QStringList * listFiles(QString sDir);
    //list dir in a dir (excluding files)
    QStringList * listDirs(QString sDir);
}

#endif // CONTROLEUR_H
