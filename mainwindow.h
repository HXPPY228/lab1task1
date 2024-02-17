#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Door *door;
    Window *window1 , *window2;

protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};




#endif // MAINWINDOW_H
