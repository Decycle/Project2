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
    AppController::Console = this->ui->console;
    this->stadiumMaster = new StadiumMaster();
    this->canvas = new CanvasManager(this->ui->graphicsView);
    this->loggedIn = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectStadium(int i)
{
    AppController::SelectStadium(i);
    AppController::Vertices[i]->setOpacity(1.0);
}

void MainWindow::clearSelection()
{
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        AppController::SelectStadium(i, false);
        AppController::Vertices[i]->setOpacity(0.0);
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

    for(int i = 0; i < AppController::StadiumCount; i ++)
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

    int points[1000] = {p};
    int pointsCount = 0;

    QString output = "";
    QString path = "";

    while(p != -1)
    {
        pointsCount ++;
        path += AppController::Stadiums[p]->name + "-> \n";
        p = shortest_paths[p][1];
        points[pointsCount] = p;
    }

    if(shortest_paths[pointB][0] > 100000)
    {
        this->ui->console->setText("Path Not Found");
        return;
    }

    output += "Total Distance Travelled: " + QString::number(shortest_paths[pointB][0]) + '\n';
    output += "Total Stadiums Visited: " + QString::number(pointsCount) + '\n';
    output += "Path: \n" + path.chopped(4);

    this->ui->console->setText(output);

    this->canvas->startAnimation(points, pointsCount);
}

void MainWindow::on_randomStadiumBtn_clicked()
{
    int index = QRandomGenerator::global()->generate() % AppController::StadiumCount;
    this->ui->console->setText(QString::fromStdString(AppController::Stadiums[index]->str()));
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
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        AppController::SelectStadium(i, false);
        AppController::Vertices[i]->update();
    }

    this->ui->console->setText("");
}


void MainWindow::on_editStadiumBtn_clicked()
{
    int stadium = -1;

    for(int i = 0; i < 1000; i ++)
    {
        if(AppController::SelectStadiumIndex[i])
        {
            stadium = i;
            qDebug() << i;
        }
    }

    if(stadium == -1)
    {
        this->ui->console->setText("No vertex selected");
        return;
    }
    StadiumEditPage stadiumEditPage(nullptr, AppController::Stadiums[stadium]);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}

void MainWindow::on_showSelectedStadiumsBtn_clicked()
{
    string output;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if(AppController::SelectStadiumIndex[i])
        {
            output += AppController::Stadiums[i]->str() + '\n';
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
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        selectStadium(i);
    }
}


void MainWindow::on_tableViewBtn_clicked()
{
    TableViewPage tableViewpage(nullptr);
    tableViewpage.setModal(true);
    tableViewpage.exec();
}


void MainWindow::on_newStadiumBtn_clicked()
{
    AppController::StadiumCount ++;
    this->stadiumMaster->addStadium();
    this->canvas->addVertex(100, 100, AppController::Stadiums[AppController::StadiumCount - 1]);

    StadiumEditPage stadiumEditPage(nullptr, AppController::Stadiums[AppController::StadiumCount - 1]);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}


void MainWindow::on_newPathBtn_clicked()
{
    AppController::LineCount ++;

    int pointA = -1;
    int pointB = -1;

    for(int i = 0; i < AppController::StadiumCount; i ++)
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

    int length = this->canvas->addLine(pointA, pointB);
    this->stadiumMaster->addPath(pointA, pointB, length);
}

