#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tableviewpage.h"
#include "vertexItem.h"
#include "loginpage.h"
#include "stadiumeditpage.h"
#include "appcontroller.h"
#include "souvenir.h"
#include "editsouvenir.h"

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QRandomGenerator>

/**********************************************************
* Method MainWindow(): Class MainWindow
*_________________________________________________________
* This method is a default constructor
*_________________________________________________________
* PRE-CONDITIONS
*      QWidget
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AppController::Console = this->ui->console;
    AppController::GraphicsView = this->ui->graphicsView;
    this->stadiumMaster = new StadiumMaster();
    this->canvas = new CanvasManager(this->ui->graphicsView);
}

/**********************************************************
* Method MainWindow(): Class MainWindow
*_________________________________________________________
* This method delete a default constructor
*_________________________________________________________
* PRE-CONDITIONS
*
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/**********************************************************
* Method MainWindow(): Class MainWindow
*_________________________________________________________
* This method will update selected stadium
*_________________________________________________________
* PRE-CONDITIONS
*      int
*
* POST-CONDITIONS
***********************************************************/
void MainWindow::selectStadium(int i)
{
    AppController::SelectStadium(i);
}

/**********************************************************
* Method clearSelection(): Class MainWindow
*_________________________________________________________
* This method will init selected stadium
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     none
***********************************************************/
void MainWindow::clearSelection()
{
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        AppController::SelectStadium(i, false);
    }
}

/**********************************************************
* Method login(): Class MainWindow
*_________________________________________________________
* This method will init login page
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     none
***********************************************************/
void MainWindow::login()
{
    AppController::IsLoggedIn = true;
    this->ui->editSouvenirBtn->setEnabled(true);
    this->ui->editStadiumBtn->setEnabled(true);
    this->ui->newStadiumBtn->setEnabled(true);
    this->ui->newPathBtn->setEnabled(true);
    this->ui->loginBtn->setText("LOGOUT");
}

/**********************************************************
* Method on_startPathBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will print out the stadium path info
* when click on the startpath button
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
void MainWindow::on_startPathBtn_clicked()
{
    int pointA = -1;
    int pointB = -1;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i])
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
    QString souvenirs = "";
    double totalSpent = 0;

    while(p != -1)
    {
        pointsCount ++;
        path += AppController::Stadiums[p]->name + "-> \n";
        souvenirs += AppController::Stadiums[p]->name + "\n";
        souvenirs += QString::fromStdString(AppController::Stadiums[p]->souvenir.to_str()) + "\n";
        totalSpent += AppController::Stadiums[p]->souvenir.totalPrice();
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
    output += "Path: \n" + path.chopped(4) + "\n\n";
    output += "Souvenirs: \nTotal Spent:" + QString::number(totalSpent) + "\n\n";
    output += souvenirs.chopped(2);

    this->ui->console->setText(output);

    this->canvas->startAnimation(points, pointsCount);
}

/**********************************************************
* Method on_randomStadiumBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will print out a random stadium info
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     none
***********************************************************/
void MainWindow::on_randomStadiumBtn_clicked()
{
    int index = QRandomGenerator::global()->generate() % AppController::StadiumCount;
    this->ui->console->setText(QString::fromStdString(AppController::Stadiums[index]->str()));


//    Souvenir s;
    AppController::Stadiums[index]->souvenir.to_str();
}

/**********************************************************
* Method on_loginBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will enable these method when login in succeed
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     enable function after login succeed
***********************************************************/
void MainWindow::on_loginBtn_clicked()
{
    if(!AppController::IsLoggedIn)
    {
        LoginPage loginPage(nullptr, this);
        loginPage.setModal(true);
        loginPage.exec();
    }

    else if(AppController::IsLoggedIn)
    {
        AppController::IsLoggedIn = false;
        this->ui->editStadiumBtn->setEnabled(false);
        this->ui->editSouvenirBtn->setEnabled(false);
        this->ui->newStadiumBtn->setEnabled(false);
        this->ui->newPathBtn->setEnabled(false);
        this->ui->loginBtn->setText("LOGIN");
    }
}

/**********************************************************
* Method on_clearAllBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will reset input
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     none
***********************************************************/
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

/**********************************************************
* Method on_editStadiumBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to edis stadium
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_editStadiumBtn_clicked()
{
    int stadium = -1;

    for(int i = 0; i < 1000; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i])
        {
            stadium = i;
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

/**********************************************************
* Method on_showSelectedStadiumsBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will show select stadium
*_________________________________________________________
* PRE-CONDITIONS
*      QWidget
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
void MainWindow::on_showSelectedStadiumsBtn_clicked()
{
    string output;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i])
        {
            output += AppController::Stadiums[i]->str() + '\n';
        }
    }

    this->ui->console->setText(QString::fromStdString(output));
}

/**********************************************************
* Method on_searchStadiumsBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to search stadium with input
* stadium name
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_searchStadiumsBtn_clicked()
{
    StadiumEditPage stadiumEditPage(nullptr, this);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}

/**********************************************************
* Method on_selectAllBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will update selected stadium
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_selectAllBtn_clicked()
{
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        selectStadium(i);
    }
}

/**********************************************************
* Method on_tableViewBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will print out table of stadium info
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_tableViewBtn_clicked()
{
    TableViewPage tableViewpage(nullptr);
    tableViewpage.setModal(true);
    tableViewpage.exec();
}

/**********************************************************
* Method on_newStadiumBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to create new stadium
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_newStadiumBtn_clicked()
{
    AppController::StadiumCount ++;
    this->stadiumMaster->addStadium();
    this->canvas->addVertex(100, 100, AppController::Stadiums[AppController::StadiumCount - 1]);

    StadiumEditPage stadiumEditPage(nullptr, AppController::Stadiums[AppController::StadiumCount - 1]);
    stadiumEditPage.setModal(true);
    stadiumEditPage.exec();
}

/**********************************************************
* Method on_newPathBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to create new path
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_newPathBtn_clicked()
{
    AppController::LineCount ++;

    int pointA = -1;
    int pointB = -1;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i])
        {
            if(pointA == -1)
                pointA = i;
            else
                pointB = i;
        }
    }

    if(pointA == -1 || pointB == -1)
    {
        this->ui->console->setText("Please select at least two vertices");
        return;
    }

    int length = this->canvas->addLine(pointA, pointB);
    this->stadiumMaster->addPath(pointA, pointB, length);
}

/**********************************************************
* Method on_startTripBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to start print out trip path
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_startTripBtn_clicked()
{
    int startPoint = AppController::StartingStadium;
    if(startPoint == -1)
    {
        AppController::Console->setText("Please select a starting point");
        return;
    }

    int* chosenPoints;
    int chosenPointsLength = 0;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i] && AppController::StartingStadium != i)
        {
            chosenPointsLength ++;
        }
    }
    if(chosenPointsLength < 1)
    {
        AppController::Console->setText("Please select at least one stadium to visit along the way");
        return;
    }

    chosenPoints = new int[chosenPointsLength];
    int index = 0;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i] && AppController::StartingStadium != i)
        {
            chosenPoints[index] = i;
            index ++;
        }
    }
    int* shortestPath = new int[1000];
    int* shortestPathCount = new int;
    int* shortestDistance = new int;
    *shortestPathCount = 0;
    *shortestDistance = 0;
    this->stadiumMaster->stadiumGraph.findShortestTrip(startPoint,
                                                       chosenPoints,
                                                       chosenPointsLength,
                                                       shortestPath,
                                                       shortestPathCount,
                                                       shortestDistance);

    if(*shortestDistance > 10000)
    {
        AppController::Console->setText("Path Not Found");
        return;
    }

    QString souvenirs;
    QString path;
    double totalSpent = 0;

    for(int i = 0; i < *shortestPathCount; i ++)
    {
        path += AppController::Stadiums[shortestPath[i]]->name + "-> \n";
        souvenirs += AppController::Stadiums[shortestPath[i]]->name + "\n";
        souvenirs += QString::fromStdString(AppController::Stadiums[shortestPath[i]]->souvenir.to_str()) + "\n";
        totalSpent += AppController::Stadiums[shortestPath[i]]->souvenir.totalPrice();
    }

    QString output;
    output += "Total Distance Travelled: " + QString::number(*shortestDistance) + '\n';
    output += "Total Stadiums Visited: " + QString::number(*shortestPathCount) + '\n';
    output += "Path: \n" + path.chopped(4) + "\n\n";
    output += "Souvenirs: \nTotal Spent:" + QString::number(totalSpent) + "\n\n";
    output += souvenirs.chopped(2);

    AppController::Console->setText(output);

    this->canvas->startAnimation(shortestPath, *shortestPathCount);

    delete[] shortestPath;
    delete shortestPathCount;
    delete[] chosenPoints;
    delete shortestDistance;

}

/**********************************************************
* Method on_showNameBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to show all stadium name
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_showNameBtn_clicked()
{
    AppController::ShowName = !AppController::ShowName;
    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        AppController::GraphicsView->update();
    }
}

/**********************************************************
* Method on_editSouvenirBtn_clicked(): Class MainWindow
*_________________________________________________________
* This method will allow user to edit souvenir list
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*
***********************************************************/
void MainWindow::on_editSouvenirBtn_clicked()
{
    int stadium = -1;

    for(int i = 0; i < 1000; i ++)
    {
        if((*AppController::SelectStadiumIndex)[i])
        {
            stadium = i;
        }
    }

    if(stadium == -1)
    {
        this->ui->console->setText("No vertex selected");
        return;
    }

    EditSouvenir editSouvenir(nullptr, stadium);
    editSouvenir.setModal(true);
    editSouvenir.exec();
}

