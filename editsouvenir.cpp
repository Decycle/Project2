#include "editsouvenir.h"
#include "ui_editsouvenir.h"
#include "appcontroller.h"
#include "stadium.h"
#include "souvenir.h"


/************
 * CONSTRUCTOR *
 * **********/

/*************************************************
 * Method EditSouvenir(): Class EditSouvenir
 * _______________________________________________
 * COnstructor for EditSouvenir class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Initalized the EditSouvenir page.
 * ***********************************************/
EditSouvenir::EditSouvenir(QWidget *parent, int index) :
    QDialog(parent),
    ui(new Ui::EditSouvenir)
{
    ui->setupUi(this);
    this->index = index;

    Stadium *stadium = AppController::Stadiums[index];
    this->ui->tableWidget->setRowCount(20);
    this->ui->tableWidget->setColumnWidth(0, 150);

    for(int i = 0; i < stadium->souvenir.count; i ++)
    {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(stadium->souvenir.names[i]));
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(stadium->souvenir.prices[i]));
        this->ui->tableWidget->setItem(i, 0, nameItem);
        this->ui->tableWidget->setItem(i, 1, priceItem);
    }
}

/****************
 * DECONSTRUCTOR *
 * **************/

/*************************************************
 * Method ~EditSouvenir(): Class EditSouvenir
 * _______________________________________________
 * Deconstructor for EditSouvenir class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Deleted the EditSouvenir page.
 * ***********************************************/
EditSouvenir::~EditSouvenir()
{
    delete ui;
}
/*************************************************
 * Method on_cancelBtn_clicked(): Class EditSouvenir
 * _______________________________________________
 * Cancel button clicked.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Closes the EditSouvenir page.
 * ***********************************************/
void EditSouvenir::on_cancelBtn_clicked()
{
    this->close();
}
/*************************************************
 * Method on_saveBtn_clicked(): Class EditSouvenir
 * _______________________________________________
 * Saves the souvenir information.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Saves the souvenir information.
 * ***********************************************/
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

