#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QStringList>
#include <QDir>

namespace Controleur
{

    //list files in a dir (excluding dirs)
    // returns -1 if not accessible
    bool listFiles(QString isDir, QStringList &ioFileList);
    //list dir in a dir (excluding files)
    // returns -1 if not accessible
    bool listDirs(QString isDir, QStringList &ioDirList);
}

#endif // CONTROLEUR_H
