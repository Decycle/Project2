#include "vertexItem.h"
#include "appcontroller.h"

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

void VertexItem::setStadium(Stadium *stadium)
{
    this->stadium = stadium;
}

void VertexItem::setAlternativeStadium(Stadium *stadium)
{
    this->alternativeStadium = stadium;
}

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
