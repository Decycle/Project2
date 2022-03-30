#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QPen>
#include <QDebug>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this->ui->graphicsView);
    this->ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPen pen(Qt::white);

    int height = this->ui->graphicsView->height();
    int width = this->ui->graphicsView->width();


    int randomX1 = QRandomGenerator::global()->generate() % width;
    int randomX2 = QRandomGenerator::global()->generate() % width;
    int randomY1 = QRandomGenerator::global()->generate() % height;
    int randomY2 = QRandomGenerator::global()->generate() % height;

    qDebug() << height << " " << width;
    scene->addLine(randomX1, randomY1, randomX2, randomY2, pen);

//    this->ui->graphicsView->
}

