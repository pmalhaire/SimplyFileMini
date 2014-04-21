#include "simplyview.h"
#include "simplyweb.h"
#include "controleur.h"
#include <QWebFrame>
#include <QVariantList>

SimplyView::SimplyView(QWidget *parent) :
    QGraphicsView(parent)
{
    m_SimplyWeb=new SimplyWeb();
    setFrameShape(QFrame::NoFrame);
    QGraphicsScene *scene = new QGraphicsScene;
    setScene(scene);
    setFrameShape(QFrame::NoFrame);
    setFixedHeight(800);
    setFixedWidth(600);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->addItem(m_SimplyWeb);
    scene->setActiveWindow(m_SimplyWeb);
    connect(m_SimplyWeb->page()->mainFrame(),
            SIGNAL(javaScriptWindowObjectCleared()), SLOT(addToJavaScript()));
}

SimplyView::~SimplyView()
{
            if(this->scene())this->scene()->clear();
            if(NULL != this->scene()) qDeleteAll(this->scene()->items());
            //can do that risk of free out of scope
            //if(NULL != m_SimplyWeb) delete m_SimplyWeb;
}

void SimplyView::quit()
{
    emit quitRequested();
}



QVariantList SimplyView::listFiles(QString sDir)
{

    QStringList * strList = Controleur::listFiles(sDir);
    QVariantList newList;

    if(strList==NULL) return newList;

    QStringListIterator fileIt(*strList);

    while (fileIt.hasNext()) newList << fileIt.next();

    delete strList;
    return newList;
}

QVariantList SimplyView::listDirs(QString sDir)
{
    QStringList * strList = Controleur::listDirs(sDir);
    QVariantList newList;
    if(strList==NULL) return newList;
    QStringListIterator dirIt(*strList);

    while (dirIt.hasNext()) newList << dirIt.next();

    delete strList;
    return newList;
}

void SimplyView::addToJavaScript()
{
    m_SimplyWeb->page()->mainFrame()->addToJavaScriptWindowObject("Lima", this);
}
