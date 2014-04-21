#ifndef SIMPLYWIDGET_H
#define SIMPLYWIDGET_H

#include <QWidget>


class SimplyView;

class SimplyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SimplyWidget(QWidget *parent = 0);
    ~SimplyWidget();

signals:

public slots:

public:
    SimplyView* m_pSimplyView;
};

#endif // SIMPLYWIDGET_H
