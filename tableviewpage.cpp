#include "tableviewpage.h"
#include "ui_tableviewpage.h"
#include "appcontroller.h"
#include <QTableWidgetItem>

/***********
 * CONSTRUCTOR *
 * **********/

/*************************************************
 * Method TableViewPage(): Class TableViewPage
 * _______________________________________________
 * COnstructor for TableViewPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Initalized the TableViewPage page.
 * ***********************************************/
TableViewPage::TableViewPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableViewPage)
{
    ui->setupUi(this);

    this->ui->tableWidget->setRowCount(AppController::StadiumCount);
    this->ui->tableWidget->setColumnWidth(0, 200);
    this->ui->tableWidget->setColumnWidth(1, 100);
    this->ui->tableWidget->setColumnWidth(2, 200);
    this->ui->tableWidget->setColumnWidth(3, 100);
    this->ui->tableWidget->setColumnWidth(4, 200);
    this->ui->tableWidget->setColumnWidth(5, 100);
    this->ui->tableWidget->setColumnWidth(6, 100);

    int count = 0;

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        if(!(*AppController::SelectStadiumIndex)[i])
        {
            continue;
        }

        QTableWidgetItem *nameItem = new QTableWidgetItem(AppController::Stadiums[i]->name);
        QTableWidgetItem *capacityItem = new QTableWidgetItem(QString::number(AppController::Stadiums[i]->capacity));
        QTableWidgetItem *locationItem = new QTableWidgetItem(AppController::Stadiums[i]->location);
        QTableWidgetItem *grassItem = new QTableWidgetItem(AppController::Stadiums[i]->hasGrass ? "Grass" : "Artificial Turf");
        QTableWidgetItem *teamItem = new QTableWidgetItem(AppController::Stadiums[i]->team);
        QTableWidgetItem *openedItem = new QTableWidgetItem(QString::number(AppController::Stadiums[i]->opened));
        QTableWidgetItem *AmericaItem = new QTableWidgetItem(AppController::Stadiums[i]->isAmerican ? "American" : "National");
        this->ui->tableWidget->setItem(count, 0, nameItem);
        this->ui->tableWidget->setItem(count, 1, capacityItem);
        this->ui->tableWidget->setItem(count, 2, locationItem);
        this->ui->tableWidget->setItem(count, 3, grassItem);
        this->ui->tableWidget->setItem(count, 4, teamItem);
        this->ui->tableWidget->setItem(count, 5, openedItem);
        this->ui->tableWidget->setItem(count, 6, AmericaItem);
        count++;
    }

    this->ui->tableWidget->setSortingEnabled(true);

}

/****************
 * DECONSTRUCTOR *
 * **************/

/*************************************************
 * Method ~TableViewPage(): Class TableViewPage
 * _______________________________________________
 * Deconstructor for TableViewPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Deleted the TableViewPage page.
 * ***********************************************/
TableViewPage::~TableViewPage()
{
    delete ui;
}

/*************************************************
 * Method on_cancelBtn_clicked(): Class TableViewPage
 * _______________________________________________
 * Overload Constructor for TableViewPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Deleted the TableViewPage page.
 * ***********************************************/
void TableViewPage::on_returnBtn_clicked()
{
    this->close();
}

