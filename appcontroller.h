#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "stadium.h"
#include "vertexItem.h"
#include "lineitem.h"

#include <QBitArray>
#include <QGraphicsView>

class AppController
{
public:
    inline static Stadium** Stadiums = new Stadium*[1000];
    inline static QBitArray* SelectStadiumIndex = new QBitArray(1000);
    inline static VertexItem** Vertices = new VertexItem*[1000];
    inline static LineItem** Lines = new LineItem*[1000];
    inline static QTextBrowser* Console = nullptr;
    inline static QGraphicsView* GraphicsView = nullptr;
    inline static int StadiumCount = 30;
    inline static int LineCount = 54;
    inline static bool IsLoggedIn = false;
    inline static int StartingStadium = -1;
    inline static bool ShowName = false;

    static void SelectStadium(int i, bool value = true)
    {
        AppController::SelectStadiumIndex->setBit(i, value);
        AppController::Vertices[i]->update();
    }
    AppController();

};

#endif // APPCONTROLLER_H
