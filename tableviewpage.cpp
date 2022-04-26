#include "tableviewpage.h"
#include "ui_tableviewpage.h"
#include "appcontroller.h"
#include <QTableWidgetItem>

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

    for(int i = 0; i < AppController::StadiumCount; i ++)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(AppController::Stadiums[i]->name);
        QTableWidgetItem *capacityItem = new QTableWidgetItem(QString::number(AppController::Stadiums[i]->capacity));
        QTableWidgetItem *locationItem = new QTableWidgetItem(AppController::Stadiums[i]->location);
        QTableWidgetItem *grassItem = new QTableWidgetItem(AppController::Stadiums[i]->hasGrass ? "Grass" : "Artificial Turf");
        QTableWidgetItem *teamItem = new QTableWidgetItem(AppController::Stadiums[i]->team);
        QTableWidgetItem *openedItem = new QTableWidgetItem(QString::number(AppController::Stadiums[i]->opened));
        QTableWidgetItem *AmericaItem = new QTableWidgetItem(AppController::Stadiums[i]->isAmerican ? "American" : "National");
        this->ui->tableWidget->setItem(i, 0, nameItem);
        this->ui->tableWidget->setItem(i, 1, capacityItem);
        this->ui->tableWidget->setItem(i, 2, locationItem);
        this->ui->tableWidget->setItem(i, 3, grassItem);
        this->ui->tableWidget->setItem(i, 4, teamItem);
        this->ui->tableWidget->setItem(i, 5, openedItem);
        this->ui->tableWidget->setItem(i, 6, AmericaItem);
    }

    this->ui->tableWidget->setSortingEnabled(true);

}

TableViewPage::~TableViewPage()
{
    delete ui;
}

void TableViewPage::on_returnBtn_clicked()
{
    this->close();
}

