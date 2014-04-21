#include "simplywidget.h"
#include "simplyview.h"
#include <QVBoxLayout>

SimplyWidget::SimplyWidget(QWidget *parent)
    : QWidget(parent)
    , m_pSimplyView(new SimplyView(this))
{
    connect(m_pSimplyView, SIGNAL(quitRequested()), SLOT(close()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_pSimplyView);
    layout->setMargin(0);
    setLayout(layout);
}



SimplyWidget::~SimplyWidget(){
    delete m_pSimplyView;
}
