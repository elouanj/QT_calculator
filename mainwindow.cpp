/*using namespace std;
#include <iostream>*/

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QAction>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::bClicked(int value)
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


}

void MainWindow::bresultClicked(QLCDNumber *screen)
{
    int result;
    for(int i=0; i<sizeof(operations); i++)
    {
        switch (operations[i])
        {
        case -1:
            values[i+1] = values[i] + values[i+1];
            break;
        case -2:
            values[i+1] = values[i] - values[i+1];
            break;
        case -3:
            values[i+1] = values[i] * values[i+1];
            break;
        case -4:
            values[i+1] = values[i] / values[i+1];
            break;
        }
        /*if(operations[i] == -3 || operations[i] == -4)
        {

        }
    }

    qInfo() << values.back();
    values.clear();
    operations.clear();
    endNumber = true;
    screen->display(values.back());
}*/
