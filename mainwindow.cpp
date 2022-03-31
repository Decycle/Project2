#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this->ui->graphicsView);
    this->ui->graphicsView->setScene(scene);


    QImage bgImg(":/ui/background.png");
    scene->addPixmap(QPixmap::fromImage(bgImg));

    const int vertices[25][2] ={
        {90, 62},
        {37, 240},
        {79, 325},
        {95, 351},
        {174, 357},
        {297, 247},
        {416, 394},
        {440, 465},
        {455, 267},
        {465, 154},
        {513, 276},
        {543, 183},
        {548, 210},
        {608, 195},
        {605, 256},
        {619, 361},
        {635, 210},
        {668, 152},
        {670, 221},
        {667, 469},
        {703, 509},
        {715, 239},
        {734, 215},
        {753, 197},
        {780, 162}
    };

    const int edges[25][2] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 8},
        {8, 9},
        {9, 10},
        {10, 11},
        {11, 12},
        {12, 13},
        {13, 14},
        {14, 15},
        {15, 16},
        {16, 17},
        {17, 18},
        {18, 19},
        {19, 20},
        {20, 21},
        {21, 22},
        {22, 23},
        {23, 24},
        {24, 0}
    };

    lines = new Line*[25];

    for(int i = 0; i < 25; i++) {
        Line *line = new Line(vertices[edges[i][0]][0], vertices[edges[i][0]][1],
                              vertices[edges[i][1]][0], vertices[edges[i][1]][1]);
        line->addToScene(scene);
        lines[i] = line;
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));

//    timer->start(40);
    step = 0;
}

MainWindow::~MainWindow()
{
    delete[] lines;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    timer->start(40);
}

void MainWindow::advance()
{
    const float SPEED = 5;

    float steps = step * SPEED;
    // line->setDistance(steps);
    // line2->setDistance(steps - line->length());

    step += 1;
}
