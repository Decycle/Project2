#include "vertexItem.h"
#include "appcontroller.h"

/**********************************************************
 *
 * VertexItem(qreal x, qreal y, qreal width,
           qreal height, int index, bool isMovable)
    :QGraphicsEllipseItem(x, y, width, height)
 *_________________________________________________________
 * This function is set the vertex
 *_________________________________________________________
 * PRE-CONDITIONS
 *  x : horizontal
 *  y : vertical
 *  posX : postion for x
 *  posY : postion for y
 *  index : index
 *  isMovable: it is Movable
 * POST-CONDITIONS
 *  This function is set the vertex
 ***********************************************************/
VertexItem::VertexItem(qreal x, qreal y, qreal width,
           qreal height, int index, bool isMovable)
    :QGraphicsEllipseItem(x, y, width, height)
{
    this->x = x;
    this->y = y;
    this->posX = x;
    this->posY = y;
    this->index = index;
    this->isMovable = isMovable;

    this->setAcceptDrops(true);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

/**********************************************************
 *
 * setStadium(Stadium *stadium)
 *_________________________________________________________
 * This function is set the stadium
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *  This function is set the stadium
 ***********************************************************/
void VertexItem::setStadium(Stadium *stadium)
{
    this->stadium = stadium;
}

/**********************************************************
 *
 * setAlternativeStadium(Stadium *stadium);
 *_________________________________________________________
 * This function is set the alternative stadium
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *  This function is set the alternative stadium
 ***********************************************************/
void VertexItem::setAlternativeStadium(Stadium *stadium)
{
    this->alternativeStadium = stadium;
}

/**********************************************************
 *
 * paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
 *_________________________________________________________
 * This function is paint the vertex
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *  This function is output the vertex
 ***********************************************************/
void VertexItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if(AppController::ShowName)
    {
        painter->setPen(Qt::black);
        painter->drawText(x + 3, y + 3, AppController::Stadiums[index]->name);
    }
    painter->setPen(Qt::NoPen);

    if((*AppController::SelectStadiumIndex)[index])
    {
        if(AppController::StartingStadium == index)
        {
            painter->setBrush(QBrush(QColor(65, 172, 176)));
        }
        else
        {
            painter->setBrush(QBrush(QColor(245, 59, 59)));
        }
        painter->drawEllipse(x, y, 22, 22);
    }


    if(isMovable)
    {
        painter->setBrush(QColor(201, 255, 203));
    }
    else
    {
        painter->setBrush(Qt::white);
    }
    painter->drawEllipse(x + 3, y + 3, 16, 16);
}

/**********************************************************
 *
 * mousePressEvent(QGraphicsSceneMouseEvent* event)
 *_________________________________________________________
 * This function creat the mouse press
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *  This function creat the mouse press
 ***********************************************************/
void VertexItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if(alternativeStadium != nullptr)
        {
            AppController::Console->setText(QString::fromStdString(stadium->str() + '\n' + alternativeStadium->str()));
        }
        else
        {
            AppController::Console->setText(QString::fromStdString(stadium->str()));
        }
    }
    else if (event->buttons() & Qt::RightButton)
    {
        if(!(*AppController::SelectStadiumIndex)[index])
        {
            (*AppController::SelectStadiumIndex)[index] = true;
            this->update();
        }
        else
        {
            if(AppController::StartingStadium == index)
            {
                AppController::Vertices[AppController::StartingStadium]->update();
                AppController::StartingStadium = -1;
            }
            (*AppController::SelectStadiumIndex)[index] = false;
            this->update();
        }

    }
    else if(event->buttons() & Qt::MiddleButton)
    {
        if(AppController::StartingStadium == index)
        {
            AppController::Vertices[AppController::StartingStadium]->update();
            AppController::StartingStadium = -1;
            (*AppController::SelectStadiumIndex)[index] = false;
            this->update();
        }
        else
        {
            AppController::StartingStadium = index;
            (*AppController::SelectStadiumIndex)[index] = true;
            this->update();
        }
    }
}

/**********************************************************
 *
 * mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 *_________________________________________________________
 * This function is create the mouseMove Event
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *  This function is create the mouseMove Event.
 ***********************************************************/
void VertexItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isMovable)
    {
        return;
    }

    this->setPos(event->scenePos().x() - x - 11, event->scenePos().y() - y - 11);
    this->posX = event->scenePos().x() - 11;
    this->posY = event->scenePos().y() - 11;
    AppController::GraphicsView->update();
}
