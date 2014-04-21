#include "simplyview.h"
#include "simplyweb.h"
#include "controleur.h"
#include <QWebFrame>
#include <QVariantList>

SimplyView::SimplyView(QWidget *parent) :
    QGraphicsView(parent)
{
    m_pSimplyWeb=new SimplyWeb();

    setFrameShape(QFrame::NoFrame);
    setFixedHeight(800);
    setFixedWidth(600);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsScene *pScene = new QGraphicsScene;
    setScene(pScene);
    pScene->addItem(m_pSimplyWeb);
    pScene->setActiveWindow(m_pSimplyWeb);
    connect(m_pSimplyWeb->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(_addToJavaScript()));
}

SimplyView::~SimplyView()
{
            if(this->scene())this->scene()->clear();
            if(NULL != this->scene()) qDeleteAll(this->scene()->items());
            //can do that risk of free out of scope
            //if(NULL != m_pSimplyWeb) delete m_pSimplyWeb;
}

void SimplyView::quit()
{
    emit quitRequested();
}

void SimplyView::resizeEvent(QResizeEvent *event)
{
    m_pSimplyWeb->resize(event->size());
}


QVariantList SimplyView::listFiles(QString isDir)
{

    QStringList * strList = Controleur::listFiles(isDir);
    QVariantList newList;

    if(strList==NULL) return newList;

    QStringListIterator fileIt(*strList);

    while (fileIt.hasNext()) newList << fileIt.next();

    delete strList;
    return newList;
}

QVariantList SimplyView::listDirs(QString isDir)
{
    QStringList * strList = Controleur::listDirs(isDir);
    QVariantList newList;
    if(strList==NULL) return newList;
    QStringListIterator dirIt(*strList);

    while (dirIt.hasNext()) newList << dirIt.next();

    delete strList;
    return newList;
}

void SimplyView::_addToJavaScript()
{
    m_pSimplyWeb->page()->mainFrame()->addToJavaScriptWindowObject("Lima", this);
}
