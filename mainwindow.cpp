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

    const int edges[49][3] = {
        {0, 1, 680},
        {1, 2, 340},
        {2, 3, 110},
        {3, 4, 300},
        {1, 4, 650},
        {4, 5, 580},
        {3, 5, 830},
        {2, 9, 1500},
        {4, 6, 870},
        {4, 7, 1115},
        {6, 7, 230},
        {5, 6, 650},
        {6, 8, 460},
        {5, 8, 560},
        {5, 6, 650},
        {0, 9, 1390},
        {7, 10, 680},
        {8, 10, 235},
        {9, 10, 465},
        {9, 11, 300},
        {11, 12, 80},
        {8, 12, 415},
        {10, 14, 310},
        {12, 14, 250},
        {6, 15, 740},
        {7, 19, 790},
        {7, 20, 965},
        {0, 17, 2070},
        {11, 17, 430},
        {12, 13, 240},
        {13, 16, 90},
        {14, 16, 225},
        {14, 15, 375},
        {19, 20, 210},
        {15, 20, 600},
        {14, 19, 790},
        {15, 21, 560},
        {21, 20, 930},
        {13, 17, 210},
        {16, 18, 115},
        {14, 18, 260},
        {17, 18, 225},
        {17, 24, 430},
        {18, 23, 315},
        {18, 21, 195},
        {21, 22, 90},
        {22, 23, 80},
        {23, 24, 195},
        {20, 24, 1255},
    };

    for(int i = 0; i < 25; i ++)
    {

        VertexItem *vertex = new VertexItem(vertices[i][0] - 5, vertices[i][1] - 5, 10, 10);
        vertex->setBrush(QBrush(Qt::black));
        vertex->setOpacity(0.5);
        scene->addItem(vertex);
//        scene->addEllipse(vertices[i][0] - 5, vertices[i][1] - 5, 10, 10, QPen(Qt::black), QBrush(Qt::black));
    }

    lines = new Line*[49];

    for(int i = 0; i < 49; i++) {
        Line *line = new Line(vertices[edges[i][0]][0], vertices[edges[i][0]][1],
                              vertices[edges[i][1]][0], vertices[edges[i][1]][1]);
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

    for(int i = 0; i < 49; i++)
    {
        lines[i]->setDistance(steps - lineLengths);
        lineLengths += lines[i]->length();
    }

    // line->setDistance(steps);
    // line2->setDistance(steps - line->length());

    step += 1;
}
