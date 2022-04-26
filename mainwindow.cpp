#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tableviewpage.h"
#include "vertexItem.h"
#include "loginpage.h"
#include "stadiumeditpage.h"
#include "appcontroller.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->stadiumMaster = new StadiumMaster(AppController::SelectStadiumIndex);
    this->canvas = new CanvasManager(this->ui->graphicsView, this->ui->console, this->stadiumMaster->stadiums, AppController::SelectStadiumIndex);
    AppController::Initialize(this->ui->console);
    this->loggedIn = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

Stadium** MainWindow::getStadiums()
{
    return this->stadiumMaster->stadiums;
}

void MainWindow::selectStadium(int i)
{
    AppController::SelectStadiumIndex[i] = true;
    this->canvas->vertices[i]->setOpacity(1.0);
}

void MainWindow::clearSelection()
{
    for(int i = 0; i < StadiumMaster::stadiumCount; i ++)
    {
        AppController::SelectStadiumIndex[i] = false;
        this->canvas->vertices[i]->setOpacity(0.0);
    }
}

void MainWindow::login()
{
    this->loggedIn = true;
    this->ui->editStadiumBtn->setEnabled(true);
    this->ui->loginBtn->setText("LOGOUT");
}

void MainWindow::on_startPathBtn_clicked()
{
    int pointA = -1;
    int pointB = -1;

    for(int i = 0; i < 100; i ++)
    {
        if(AppController::SelectStadiumIndex[i])
        {
            if(pointA == -1)
                pointA = i;
            else
                pointB = i;
        }
    }

    if(pointA == -1 && pointB == -1)
    {
        this->ui->console->setText("Please select at least two vertices");
        return;
    }


    int **shortest_paths = this->stadiumMaster->stadiumGraph.findShortestPaths(pointA);

    int p = pointB;

    int points[100] = {p};
    int pointsCount = 0;

    QString output = "";
    QString path = "";

    while(p != -1)
    {
        pointsCount ++;
        path += this->stadiumMaster->stadiums[p]->name + "-> \n";
        p = shortest_paths[p][1];
        points[pointsCount] = p;
    }

    output += "Total Distance Travelled: " + QString::number(shortest_paths[pointB][0]) + '\n';
    output += "Total Stadiums Visited: " + QString::number(pointsCount) + '\n';
    output += "Path: \n" + path.chopped(4);

    this->ui->console->setText(output);

    this->canvas->startAnimation(points, pointsCount);
}

void MainWindow::on_randomStadiumBtn_clicked()
{
    int index = QRandomGenerator::global()->generate() % StadiumMaster::stadiumCount;
    this->ui->console->setText(QString::fromStdString(this->stadiumMaster->stadiums[index]->str()));
}

void MainWindow::on_loginBtn_clicked()
{
    if(!this->loggedIn)
    {
        LoginPage loginPage(nullptr, this);
        loginPage.setModal(true);
        loginPage.exec();
    }

    else if(this->loggedIn)
    {
        this->loggedIn = false;
        this->ui->editStadiumBtn->setEnabled(false);
        this->ui->loginBtn->setText("LOGIN");
    }
}


void MainWindow::on_clearAllBtn_clicked()
{
    this->canvas->clearCanvas();
    for(int i = 0; i < 100; i ++)
    {
        AppController::SelectStadiumIndex[i] = false;
    }

    this->ui->console->setText("");
}


void MainWindow::on_editStadiumBtn_clicked()
{
    int stadium = -1;

    for(int i = 0; i < 100; i ++)
    {
        if(AppController::SelectStadiumIndex[i])
        {
            stadium = i;
        }
    }

    if(stadium == -1)
    {
        this->ui->console->setText("No vertex selected");
        return;
    }
    StadiumEditPage stadiumEditPage(nullptr, this->stadiumMaster->stadiums[stadium]);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}

void MainWindow::on_showSelectedStadiumsBtn_clicked()
{
    string output;

    for(int i = 0; i < 100; i ++)
    {
        if(AppController::SelectStadiumIndex[i])
        {
            output += this->stadiumMaster->stadiums[i]->str() + '\n';
        }
    }

    this->ui->console->setText(QString::fromStdString(output));
}


void MainWindow::on_searchStadiumsBtn_clicked()
{
    StadiumEditPage stadiumEditPage(nullptr, this);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}


void MainWindow::on_selectAllBtn_clicked()
{
    for(int i = 0; i < StadiumMaster::stadiumCount; i ++)
    {
        selectStadium(i);
    }
}



void MainWindow::on_tableViewBtn_clicked()
{
    TableViewPage tableViewpage(nullptr, this->stadiumMaster);
    tableViewpage.setModal(true);
    tableViewpage.exec();
}


void MainWindow::on_newStadiumBtn_clicked()
{
    StadiumMaster::stadiumCount ++;
    this->stadiumMaster->addStadium();
    this->canvas->addVertex(100, 100, this->stadiumMaster->stadiums[StadiumMaster::stadiumCount]);

    StadiumEditPage stadiumEditPage(nullptr, this->stadiumMaster->stadiums[StadiumMaster::stadiumCount]);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}


void MainWindow::on_newPathBtn_clicked()
{
    CanvasManager::lineCount ++;

    int pointA = -1;
    int pointB = -1;

    for(int i = 0; i < 100; i ++)
    {
        if(AppController::SelectStadiumIndex[i])
        {
            if(pointA == -1)
                pointA = i;
            else
                pointB = i;
        }
    }

    if(pointA == -1 && pointB == -1)
    {
        this->ui->console->setText("Please select at least two vertices");
        return;
    }

    this->canvas->addLine(pointA, pointB, 0);

}

