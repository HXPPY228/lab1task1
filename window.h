#ifndef WINDOW_H
#define WINDOW_H

#include "door.h"

class Window : public Door
{
public:
    Window(QWidget *parent = nullptr);
    bool isOpenWin;
    void togglew();
protected:
    void paintEvent(QPaintEvent *) override;
    void paintEvent1(QPaintEvent *);
};


#endif // WINDOW_H
