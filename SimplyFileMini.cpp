#include <QApplication>

#include <QWebSettings>

#include "simplywidget.h"
#include "simplyview.h"
#include "simplyweb.h"
#include <QFileInfo>
#include <QUrl>

//#define DEBUG

int main(int argc, char **argv)
{

   QApplication app(argc, argv);
#ifdef DEBUG
   QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
#endif
   SimplyWidget appView;

   QString fileName("html/index.html");
   //to avoid make function a bit anoying since it adds unwanted include
   QUrl url = QUrl::fromLocalFile(QFileInfo(fileName).absoluteFilePath());
   appView.m_pSimplyView->m_pSimplyWeb->setUrl(url);
   appView.m_pSimplyView->m_pSimplyWeb->load(url);

   appView.show();
   return app.exec();

}
