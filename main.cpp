#include "mainwindow.h"
#include "numberframe.h"

#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QAction>

Ui::MainWindow *ui;
/*vector<int> values;
vector<int> operations;
bool endNumber = true;


void bClicked(int value)
{
    //QApplication::quit();
    if(value >= 0)
    {
        if(endNumber)
        {
            values.push_back(value);
            endNumber = false;
        }
        else
        {
            values.back() = values.back() * 10 + value;
        }

    }
    else
    {
        operations.push_back(value);
        endNumber = true;
    }

    qInfo() << values;
    qInfo() << operations;


}*/


class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 12, QFont::Bold));
    quit->setShortcut(QKeySequence("q"));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    NumberFrame *numbers = new NumberFrame;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(numbers);
    layout->addWidget(quit);
    setLayout(layout);

    /*QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(screen);
    layout->addWidget(numbers);
    setLayout(layout);*/
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
