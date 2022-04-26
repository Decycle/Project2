#include "tableviewpage.h"
#include "ui_tableviewpage.h"
#include <QTableWidgetItem>

TableViewPage::TableViewPage(QWidget *parent, StadiumMaster* stadiums) :
    QDialog(parent),
    ui(new Ui::TableViewPage)
{
    ui->setupUi(this);

    this->ui->tableWidget->setRowCount(StadiumMaster::stadiumCount);
    this->ui->tableWidget->setColumnWidth(0, 200);
    this->ui->tableWidget->setColumnWidth(1, 100);
    this->ui->tableWidget->setColumnWidth(2, 200);
    this->ui->tableWidget->setColumnWidth(3, 100);
    this->ui->tableWidget->setColumnWidth(4, 200);
    this->ui->tableWidget->setColumnWidth(5, 100);
    this->ui->tableWidget->setColumnWidth(6, 100);

    for(int i = 0; i < StadiumMaster::stadiumCount; i ++)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(stadiums->stadiums[i]->name);
        QTableWidgetItem *capacityItem = new QTableWidgetItem(QString::number(stadiums->stadiums[i]->capacity));
        QTableWidgetItem *locationItem = new QTableWidgetItem(stadiums->stadiums[i]->location);
        QTableWidgetItem *grassItem = new QTableWidgetItem(stadiums->stadiums[i]->hasGrass ? "Grass" : "Artificial Turf");
        QTableWidgetItem *teamItem = new QTableWidgetItem(stadiums->stadiums[i]->team);
        QTableWidgetItem *openedItem = new QTableWidgetItem(QString::number(stadiums->stadiums[i]->opened));
        QTableWidgetItem *AmericaItem = new QTableWidgetItem(stadiums->stadiums[i]->isAmerican ? "American" : "National");
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

