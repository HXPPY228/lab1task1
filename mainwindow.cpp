#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    painter.drawRect(450, 150, 200, 350);
    painter.drawRect(150, 150, 200, 200);
}
