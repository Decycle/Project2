#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vertexItem.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsEllipseItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this->ui->graphicsView);
    this->ui->graphicsView->setScene(scene);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QImage bgImg(":/ui/background.png");
    scene->addPixmap(QPixmap::fromImage(bgImg));

    const int vertices[30][2] = {
            { 543, 183 },
            { 79, 325 },
            { 513, 276 },
            { 174, 357 },
            { 753, 197 },
            { 734, 215 },
            { 608, 195 },
            { 297, 247 },
            { 79, 325 },
            { 780, 162 },
            { 416, 394 },
            { 605, 256 },
            { 548, 210 },
            { 455, 267 },
            { 703, 509 },
            { 440, 465 },
            { 715, 239 },
            { 37, 240 },
            { 715, 239 },
            { 95, 351 },
            { 670, 221 },
            { 635, 210 },
            { 37, 240 },
            { 668, 152 },
            { 90, 62 },
            { 465, 154 },
            { 667, 469 },
            { 619, 361 },
            { 548, 210 },
            { 753, 197 }
    };
//    VertexItem *vertex = new VertexItem(vertices[i][0] - 5, vertices[i][1] - 5, 10, 10, this->ui->console);
//    vertex->setBrush(QBrush(Qt::black));
//    vertex->setOpacity(0.5);
//    scene->addItem(vertex);

//    stadiums = new Stadium*[25];
//    stadiums[0] = new Stadium(
//                "American Family Fielddouble-dagger",
//                4199,
//                "Milwaukee, Wisconsin",
//                false,
//                true,
//                "Milwaukee Brewers",
//                2001,
//                vertex
//                );



    const int edges[54][3] = {
        { 24, 17, 680 },
        { 17, 1, 340 },
        { 1, 19, 110 },
        { 19, 3, 300 },
        { 17, 3, 650 },
        { 3, 7, 580 },
        { 19, 7, 830 },
        { 1, 25, 1500 },
        { 3, 10, 870 },
        { 3, 15, 1115 },
        { 10, 15, 230 },
        { 7, 10, 650 },
        { 10, 13, 460 },
        { 7, 13, 560 },
        { 7, 10, 650 },
        { 24, 25, 1390 },
        { 15, 2, 680 },
        { 13, 2, 235 },
        { 25, 2, 465 },
        { 25, 0, 300 },
        { 0, 12, 80 },
        { 13, 12, 415 },
        { 2, 11, 310 },
        { 12, 11, 250 },
        { 10, 27, 740 },
        { 15, 26, 790 },
        { 15, 14, 965 },
        { 24, 23, 2070 },
        { 0, 23, 430 },
        { 12, 6, 240 },
        { 6, 21, 90 },
        { 11, 21, 225 },
        { 11, 27, 375 },
        { 26, 14, 210 },
        { 27, 14, 600 },
        { 11, 26, 790 },
        { 27, 16, 560 },
        { 16, 14, 930 },
        { 6, 23, 210 },
        { 21, 20, 115 },
        { 11, 20, 260 },
        { 23, 20, 225 },
        { 23, 9, 430 },
        { 20, 4, 315 },
        { 20, 16, 195 },
        { 16, 5, 90 },
        { 5, 4, 80 },
        { 4, 9, 195 },
        { 14, 9, 1255 },
        { 8, 1, 0 },
        { 17, 22, 0 },
        { 12, 28, 0 },
        { 16, 18, 0 },
        { 4, 29, 0 }
};

    for(int i = 0; i < 30; i ++)
    {

        VertexItem *vertex = new VertexItem(vertices[i][0] - 5, vertices[i][1] - 5, 10, 10, this->ui->console);
        vertex->setBrush(QBrush(Qt::black));
        vertex->setOpacity(0.5);
        scene->addItem(vertex);
    }

    lines = new Line*[54];

    for(int i = 0; i < 54; i++) {
        Line *line = new Line(vertices[edges[i][0]][0], vertices[edges[i][0]][1],
                              vertices[edges[i][1]][0], vertices[edges[i][1]][1], this->ui->console);
        line->addToScene(scene);
        lines[i] = line;
    }

//    for(int i = 0; i < 49; i++) {
//        QFont font;
//        font.setPointSize(10);
//        QGraphicsTextItem *text = scene->addText(QString::number(edges[i][2]), font);
//        text->setDefaultTextColor(Qt::black);

//        float xPos = (vertices[edges[i][0]][0] + vertices[edges[i][1]][0]) / 2.;
//        float yPos = (vertices[edges[i][0]][1] + vertices[edges[i][1]][1]) / 2.;

//        text->setPos(xPos, yPos);
//    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));

//    timer->start(40);
    step = 0;
}

MainWindow::~MainWindow()
{
    delete[] lines;
    delete[] stadiums;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    step = 0;
    timer->start(40);
}

void MainWindow::advance()
{
    const float SPEED = 15;

    float steps = step * SPEED;

    float lineLengths = 0;

    for(int i = 0; i < 54; i++)
    {
        lines[i]->setDistance(steps - lineLengths);
        lineLengths += lines[i]->length();
    }

    // line->setDistance(steps);
    // line2->setDistance(steps - line->length());

    step += 1;
}
