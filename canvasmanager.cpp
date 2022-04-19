#include "canvasmanager.h"

CanvasManager::CanvasManager(QGraphicsView *graphicsView, QTextBrowser *console, Stadium **stadiums, bool *selectStadiumIndex)
{
    scene = new QGraphicsScene(graphicsView);

    graphicsView->setScene(scene);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QImage bgImg(":/ui/background.png");
    scene->addPixmap(QPixmap::fromImage(bgImg));

    const int verticesList[30][2] = {
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
    const int edgesList[54][3] = {
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

    vertices = new VertexItem*[100];


    for(int i = 0; i < 30; i ++)
    {
        VertexItem *vertex = new VertexItem(verticesList[i][0] - 10, verticesList[i][1] - 10, 20, 20, console, i, selectStadiumIndex);
        vertex->setBrush(QBrush(Qt::black));
        vertex->setOpacity(0.01);
        scene->addItem(vertex);
        vertex->setStadium(stadiums[i]);
        vertices[i] = vertex;
    }

    //setup alternative stadiums
    vertices[1]->setAlternativeStadium(stadiums[8]);
    vertices[8]->setAlternativeStadium(stadiums[1]);
    vertices[17]->setAlternativeStadium(stadiums[22]);
    vertices[22]->setAlternativeStadium(stadiums[17]);
    vertices[12]->setAlternativeStadium(stadiums[28]);
    vertices[28]->setAlternativeStadium(stadiums[12]);
    vertices[16]->setAlternativeStadium(stadiums[18]);
    vertices[18]->setAlternativeStadium(stadiums[16]);
    vertices[4]->setAlternativeStadium(stadiums[29]);
    vertices[29]->setAlternativeStadium(stadiums[4]);


    lines = new Line*[54];

    for(int i = 0; i < 54; i++) {
        Line *line = new Line(verticesList[edgesList[i][0]][0], verticesList[edgesList[i][0]][1],
                              verticesList[edgesList[i][1]][0], verticesList[edgesList[i][1]][1], console);
        line->addToScene(scene);
        lines[i] = line;
    }

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &CanvasManager::advance);
    step = 0;
}

CanvasManager::~CanvasManager()
{
    for(int i = 0; i < 54; i++)
    {
        delete lines[i];
    }
    delete[] lines;
    delete timer;
}

void CanvasManager::advance()
{
    const float SPEED = 15;

    float steps = step * SPEED;

    float lineLengths = 0;

    for(int i = 0; i < 54; i++)
    {
        lines[i]->setDistance(steps - lineLengths);
        lineLengths += lines[i]->length();
    }

    step += 1;
}

void CanvasManager::startAnimation()
{
    step = 0;
    timer->start(40);
}
