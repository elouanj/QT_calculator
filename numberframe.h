#ifndef NUMBERFRAME_H
#define NUMBERFRAME_H

#include <QWidget>
#include <vector>
#include <QLCDNumber>

class NumberFrame : public QWidget
{
    Q_OBJECT

public:
    NumberFrame(QWidget *parent = 0);

private:
    void bClicked(int value);
    void bresultClicked();//QLCDNumber *screen);
    void setValue(int value);
    bool endNumber = true;
    std::vector<int> values;
    std::vector<int> operations;
    QLCDNumber *screen;
};

#endif // NUMBERFRAME_H
