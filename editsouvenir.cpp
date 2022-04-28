#include "editsouvenir.h"
#include "ui_editsouvenir.h"
#include "appcontroller.h"
#include "stadium.h"
#include "souvenir.h"

EditSouvenir::EditSouvenir(QWidget *parent, int index) :
    QDialog(parent),
    ui(new Ui::EditSouvenir)
{
    ui->setupUi(this);
    this->index = index;

    Stadium *stadium = AppController::Stadiums[index];
    this->ui->tableWidget->setRowCount(100);
    this->ui->tableWidget->setColumnWidth(0, 150);

    for(int i = 0; i < stadium->souvenir.count; i ++)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(stadium->souvenir.names[i]));
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(stadium->souvenir.prices[i]));
        this->ui->tableWidget->setItem(i, 0, nameItem);
        this->ui->tableWidget->setItem(i, 1, priceItem);
    }
}


EditSouvenir::~EditSouvenir()
{
    delete ui;
}

void EditSouvenir::on_cancelBtn_clicked()
{
    this->close();
}

void EditSouvenir::on_saveBtn_clicked()
{
    Stadium *stadium = AppController::Stadiums[index];
    stadium->souvenir.count = 0;

    for (int i = 0; i< this->ui->tableWidget->rowCount(); ++i)
    {
        if(!this->ui->tableWidget->item(i, 0) || !this->ui->tableWidget->item(i, 1))
        {
            continue;
        }

        string name = this->ui->tableWidget->item(i, 0)->text().toStdString();
        double price = this->ui->tableWidget->item(i, 1)->text().toDouble();

        if(name == "" || price <= 0)
        {
            continue;
        }

        stadium->souvenir.names[stadium->souvenir.count] = name;
        stadium->souvenir.prices[stadium->souvenir.count] = price;

        stadium->souvenir.count++;
    }

    this->close();
}

