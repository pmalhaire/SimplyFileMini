#ifndef SIMPLYVIEW_H
#define SIMPLYVIEW_H

#include <QGraphicsView>
#include "simplyweb.h"
#include <QStringList>

class SimplyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SimplyView(QWidget *parent = 0);
    ~SimplyView();
signals:

public slots:
    void quit();
    //list files in a dir (excluding dirs)
    QVariantList listFiles(QString sDir);
    //list dir in a dir (excluding files)
    QVariantList listDirs(QString sDir);

private slots:
    void addToJavaScript();

signals:
    void quitRequested();

public:
        SimplyWeb *m_SimplyWeb;
};

#endif // SIMPLYVIEW_H
