#include "numberframe.h"

#include <QGridLayout>
#include<QPushButton>

NumberFrame::NumberFrame(QWidget *parent)
    : QWidget(parent)
{
    //QLCDNumber *screen = new QLCDNumber;
    screen = new QLCDNumber();

    //grid creation
    QGridLayout *gridLayout = new QGridLayout;

    QPushButton *b0 = new QPushButton("0");
    b0->setShortcut(QKeySequence("0"));
    connect(b0, &QPushButton::clicked, this, [=](){ bClicked(0); });

    QPushButton *b1 = new QPushButton("1");
    b1->setShortcut(QKeySequence("1"));
    connect(b1, &QPushButton::clicked, this, [=](){ bClicked(1); });

    QPushButton *b2 = new QPushButton("2");
    b2->setShortcut(QKeySequence("2"));
    connect(b2, &QPushButton::clicked, this, [=](){ bClicked(2); });

    QPushButton *b3 = new QPushButton("3");
    b3->setShortcut(QKeySequence("3"));
    connect(b3, &QPushButton::clicked, this, [=](){ bClicked(3); });

    QPushButton *b4 = new QPushButton("4");
    b4->setShortcut(QKeySequence("4"));
    connect(b4, &QPushButton::clicked, this, [=](){ bClicked(4); });

    QPushButton *b5 = new QPushButton("5");
    b5->setShortcut(QKeySequence("5"));
    connect(b5, &QPushButton::clicked, this, [=](){ bClicked(5); });

    QPushButton *b6 = new QPushButton("6");
    b6->setShortcut(QKeySequence("6"));
    connect(b6, &QPushButton::clicked, this, [=](){ bClicked(6); });

    QPushButton *b7 = new QPushButton("7");
    b7->setShortcut(QKeySequence("7"));
    connect(b7, &QPushButton::clicked, this, [=](){ bClicked(7); });

    QPushButton *b8 = new QPushButton("8");
    b8->setShortcut(QKeySequence("8"));
    connect(b8, &QPushButton::clicked, this, [=](){ bClicked(8); });

    QPushButton *b9 = new QPushButton("9");
    b9->setShortcut(QKeySequence("9"));
    connect(b9, &QPushButton::clicked, this, [=](){ bClicked(9); });

    QPushButton *bplus = new QPushButton("+");
    bplus->setShortcut(QKeySequence("+"));
    connect(bplus, &QPushButton::clicked, this, [=](){ bClicked(-1); });

    QPushButton *bminus = new QPushButton("-");
    bminus->setShortcut(QKeySequence("-"));
    connect(bminus, &QPushButton::clicked, this, [=](){ bClicked(-2); });

    QPushButton *bmultiplication = new QPushButton("*");
    bmultiplication->setShortcut(QKeySequence("*"));
    connect(bmultiplication, &QPushButton::clicked, this, [=](){ bClicked(-3); });

    QPushButton *bdivision = new QPushButton("/");
    bdivision->setShortcut(QKeySequence("/"));
    connect(bdivision, &QPushButton::clicked, this, [=](){ bClicked(-4); });

    QPushButton *bresult = new QPushButton("=");
    bresult->setShortcut(QKeySequence("="));
    connect(bresult, &QPushButton::clicked, this, [=](){ bresultClicked(); });

    gridLayout->addWidget(bdivision,0,0,1,1);
    gridLayout->addWidget(b7,0,1,1,1);
    gridLayout->addWidget(b8,0,2,1,1);
    gridLayout->addWidget(b9,0,3,1,1);

    gridLayout->addWidget(bmultiplication,1,0,1,1);
    gridLayout->addWidget(b4,1,1,1,1);
    gridLayout->addWidget(b5,1,2,1,1);
    gridLayout->addWidget(b6,1,3,1,1);

    gridLayout->addWidget(bminus,2,0,1,1);
    gridLayout->addWidget(b1,2,1,1,1);
    gridLayout->addWidget(b2,2,2,1,1);
    gridLayout->addWidget(b3,2,3,1,1);

    gridLayout->addWidget(bplus,3,0,1,1);

    gridLayout->addWidget(b0,3,2,1,1);
    gridLayout->addWidget(bresult,3,3,1,1);

    //setLayout(gridLayout);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(screen);
    layout->addLayout(gridLayout);
    setLayout(layout);
}


void NumberFrame::bClicked(int value)
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

    setValue(values.back());
}


void NumberFrame::bresultClicked()//QLCDNumber *screen)
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

        }*/
    }

    qInfo() << values.back();
    setValue(values.back());
    values.clear();
    operations.clear();
    endNumber = true;

}

void NumberFrame::setValue(int value)
{
    screen->display(value);
}
