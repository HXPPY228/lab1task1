#ifndef DOOR_H
#define DOOR_H

#include <QWidget>

class Door : public QWidget
{

    Q_OBJECT
public:
    Door(QWidget *parent = nullptr);
    bool isOpen;
    void toggle();
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // DOOR_H
