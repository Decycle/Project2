#include "canvasmanager.h"
#include "stadiummaster.h"
#include "appcontroller.h"

CanvasManager::CanvasManager(QGraphicsView *graphicsView)
{
    scene = new QGraphicsScene(graphicsView);

    graphicsView->setScene(scene);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QImage bgImg(":/ui/background.png");
    scene->addPixmap(QPixmap::fromImage(bgImg));

    int verticesList[1000][2] = {
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
        { 440, 455 },
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

    vertexList = new int*[1000];

    for(int i = 0; i < 1000; i ++)
    {
        vertexList[i] = new int[2];
        vertexList[i][0] = verticesList[i][0];
        vertexList[i][1] = verticesList[i][1];
    }

    int edgesList[1000][3] = {
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
        { 8, 1, 1 },
        { 17, 22, 1 },
        { 12, 28, 1 },
        { 16, 18, 1 },
        { 4, 29, 1 }
    };

    edgeList = new int*[1000];

    for(int i = 0; i < 1000; i ++)
    {
        edgeList[i] = new int[3];
        edgeList[i][0] = edgesList[i][0];
        edgeList[i][1] = edgesList[i][1];
        edgeList[i][2] = edgesList[i][2];
    }

    VertexItem** vertices = new VertexItem*[1000];
    for(int i = 0; i < 30; i ++)
    {
        VertexItem *vertex = new VertexItem(verticesList[i][0] - 10,
                verticesList[i][1] - 10, 20, 20, AppController::Console, i, AppController::SelectStadiumIndex);
        vertex->setBrush(QBrush(QColor(137, 221, 139)));
        vertex->setPen(Qt::NoPen);
        vertex->setZValue(3);

        if(AppController::SelectStadiumIndex[i])
        {
            vertex->setOpacity(1.0);
        }
        else
        {
            vertex->setOpacity(0.01);
        }

        scene->addItem(vertex);
        vertex->setStadium(AppController::Stadiums[i]);
        vertices[i] = vertex;

        QGraphicsEllipseItem *circle = scene->addEllipse(verticesList[i][0] - 8, verticesList[i][1] - 8, 16, 16);
        circle->setBrush(QBrush(Qt::white));
        circle->setPen(Qt::NoPen);
        circle->setZValue(2);

//        QGraphicsTextItem *name = scene->addText(stadiums[i]->name);
//        name->setPos(verticesList[i][0], verticesList[i][1]);
//        name->setDefaultTextColor(Qt::black);
    }

    //setup alternative stadiums
    vertices[1]->setAlternativeStadium(AppController::Stadiums[8]);
    vertices[8]->setAlternativeStadium(AppController::Stadiums[1]);
    vertices[17]->setAlternativeStadium(AppController::Stadiums[22]);
    vertices[22]->setAlternativeStadium(AppController::Stadiums[17]);
    vertices[12]->setAlternativeStadium(AppController::Stadiums[28]);
    vertices[28]->setAlternativeStadium(AppController::Stadiums[12]);
    vertices[16]->setAlternativeStadium(AppController::Stadiums[18]);
    vertices[18]->setAlternativeStadium(AppController::Stadiums[16]);
    vertices[4]->setAlternativeStadium(AppController::Stadiums[29]);
    vertices[29]->setAlternativeStadium(AppController::Stadiums[4]);

    AppController::Vertices = vertices;

    lines = new Line*[1000];

    for(int i = 0; i < 54; i++) {
        Line *line = new Line(verticesList[edgesList[i][0]][0], verticesList[edgesList[i][0]][1],
                              verticesList[edgesList[i][1]][0], verticesList[edgesList[i][1]][1], edgesList[i][2]);
        line->addToScene(scene);
        lines[i] = line;
    }

    selectedLines = new int[1000];

    for(int i = 0; i < 1000; i ++)
    {
        selectedLines[i] = 0;
    }

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &CanvasManager::advance);
    step = 0;
}

CanvasManager::~CanvasManager()
{
    for(int i = 0; i < AppController::LineCount; i++)
    {
        delete lines[i];
    }
    for(int i = 0; i < 1000; i ++)
    {
        delete edgeList[i];
    }
    delete[] lines;
    delete[] selectedLines;
    delete[] edgeList;
    delete timer;
}

void CanvasManager::advance()
{
    const float SPEED = 15;

    float steps = step * SPEED;

    float lineLengths = 0;

    for(int i = 0; i < AppController::LineCount; i++)
    {
        if(selectedLines[i] >= 1)
        {
            lines[i]->setDistance(steps - lineLengths);
            lineLengths += lines[i]->length();
        }
    }

    step += 1;
}

void CanvasManager::startAnimation(int* points, int pointCount)
{
    step = 0;
    timer->start(40);

    for(int i = 0; i < 1000; i ++)
    {
        selectedLines[i] = 0;
    }

    for(int i = 0; i < pointCount - 1; i ++)
    {
        int point1 = points[i];
        int point2 = points[i + 1];

        for(int j = 0; j < AppController::LineCount; j ++)
        {
            if(edgeList[j][0] == point1 && edgeList[j][1] == point2)
            {
                selectedLines[j] = 1;
            }
            else if(edgeList[j][0] == point2 && edgeList[j][1] == point1)
            {
                selectedLines[j] = 2;
            }
        }
    }
}

void CanvasManager::clearCanvas()
{
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        AppController::Vertices[i]->setOpacity(0.01);
    }

    for(int i = 0; i < 1000; i ++)
    {
        selectedLines[i] = 0;
    }

    for(int i = 0; i < AppController::LineCount; i ++)
    {
        lines[i]->setDistance(0);
    }
}

 void CanvasManager::addVertex(int x, int y, Stadium* stadium)
 {
    int lastStadium = AppController::StadiumCount - 1;

    VertexItem *vertex = new VertexItem(x - 10, y - 10, 20, 20, AppController::Console, lastStadium, AppController::SelectStadiumIndex);
    vertex->setBrush(QBrush(QColor(137, 221, 139)));
    vertex->setPen(Qt::NoPen);
    vertex->setZValue(3);

    if(AppController::SelectStadiumIndex[lastStadium])
    {
        vertex->setOpacity(1.0);
    }
    else
    {
        vertex->setOpacity(0.01);
    }

    scene->addItem(vertex);
    vertex->setStadium(stadium);
    AppController::Vertices[lastStadium] = vertex;

    QGraphicsEllipseItem *circle = scene->addEllipse(x - 8, y - 8, 16, 16);
    circle->setBrush(QBrush(Qt::white));
    circle->setPen(Qt::NoPen);
    circle->setZValue(2);

    int* newVertice = new int[2]{x, y};

    this->vertexList[lastStadium] = newVertice;

    this->scene->update();
 }

int CanvasManager::addLine(int i, int j)
{
    int x = vertexList[j][0] - vertexList[i][0];
    int y = vertexList[j][1] - vertexList[i][1];

    int length = sqrt(x * x + y * y) * 3.21698;

    Line *line = new Line(vertexList[i][0], vertexList[i][1],
                          vertexList[j][0], vertexList[j][1], length);
    line->addToScene(scene);
    lines[AppController::LineCount - 1] = line;

    int* newEdge = new int[3] {j, i, length};
    this->edgeList[AppController::LineCount - 1] = newEdge;

    return length;
}
