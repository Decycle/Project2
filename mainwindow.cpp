#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vertexItem.h"
#include "loginpage.h"
#include "stadiumeditpage.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->stadiumMaster = new StadiumMaster(this->selectStadiumIndex);
    this->canvas = new CanvasManager(this->ui->graphicsView, this->ui->console, this->stadiumMaster->stadiums, this->selectStadiumIndex);
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
    this->selectStadiumIndex[i] = true;
    this->canvas->vertices[i]->setOpacity(1.0);
}
void MainWindow::clearSelection()
{
    for(int i = 0; i < 30; i ++)
    {
        this->selectStadiumIndex[i] = false;
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
        if(selectStadiumIndex[i])
        {
            if(pointA == -1)
                pointA = i;
            else
                pointB = i;
        }
    }


    int **shortest_paths = this->stadiumMaster->stadiumGraph.findShortestPaths(pointA);

    int p = pointB;

    int points[100] = {p};
    int pointsCount = 0;

    while(p != -1)
    {
        pointsCount ++;
        p = shortest_paths[p][1];
        points[pointsCount] = p;
    }

    this->canvas->startAnimation(points, pointsCount);
}

void MainWindow::on_randomStadiumBtn_clicked()
{
    int index = QRandomGenerator::global()->generate() % this->stadiumMaster->stadiumCount;
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
        this->selectStadiumIndex[i] = 0;
    }

    this->ui->console->setText("");
}


void MainWindow::on_editStadiumBtn_clicked()
{
    int stadium = -1;

    for(int i = 0; i < 100; i ++)
    {
        if(this->selectStadiumIndex[i])
        {
            stadium = i;
        }
    }

    if(stadium != -1)
    {
        StadiumEditPage stadiumEditPage(nullptr, this->stadiumMaster->stadiums[stadium]);
        stadiumEditPage.setModal(true);
        stadiumEditPage.exec();
    }
}

void MainWindow::on_showSelectedStadiumsBtn_clicked()
{
    string output;

    for(int i = 0; i < 100; i ++)
    {
        if(this->selectStadiumIndex[i])
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

