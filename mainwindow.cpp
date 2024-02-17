#include "mainwindow.h"
#include "ui_mainwindow.h"

Door::Door(QWidget *parent) : QWidget(parent)
{
    setFixedSize(200, 350);
}

void Door::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int flagWidth = 200;
    int flagHeight = 350;
    QRect flagRect(0, 0, flagWidth, flagHeight);

    painter.fillRect(flagRect, Qt::darkYellow);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    door = new Door(this);
    door -> move (450,150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(50, 100, 700, 400);
    // Рисуем крышу
    QPolygon roof;
    roof << QPoint(50, 100) << QPoint(750, 100) << QPoint(400, 0);
    painter.setBrush(Qt::darkGray);
    painter.drawPolygon(roof);
    // дверь и окна
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(449, 149, 201, 351);
    painter.drawRect(150, 150, 200, 200);
}


void MainWindow::on_pushButton_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(door, "pos");
    animation->setDuration(1000);
    animation->setStartValue(door->pos());
    animation->setEndValue(QPoint(door->x()+200, door->y()));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

