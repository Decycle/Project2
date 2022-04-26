#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "stadium.h"
#include "vertexItem.h"
#include "line.h"

class AppController
{
public:
    inline static Stadium** Stadiums = new Stadium*[1000];
    inline static bool SelectStadiumIndex[1000] = {false};
    inline static VertexItem** Vertices = new VertexItem*[1000];
    inline static QTextBrowser* Console = nullptr;
    inline static int StadiumCount = 30;
    inline static int LineCount = 54;

    static void Initialize(QTextBrowser* console);
    AppController();
};

#endif // APPCONTROLLER_H
