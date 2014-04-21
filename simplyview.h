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
        void resizeEvent(QResizeEvent *event);
    ~SimplyView();
signals:

public slots:
    void quit();
    //list files in a dir (excluding dirs)
    QVariantList listFiles(QString isDir);
    //list dir in a dir (excluding files)
    QVariantList listDirs(QString isDir);

private slots:
    void _addToJavaScript();

signals:
    void quitRequested();

public:
        SimplyWeb *m_pSimplyWeb;
};

#endif // SIMPLYVIEW_H
