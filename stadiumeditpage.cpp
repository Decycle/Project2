#include "stadiumeditpage.h"
#include "ui_stadiumeditpage.h"
#include <QIntValidator>

StadiumEditPage::StadiumEditPage(QWidget *parent, Stadium *stadium) :
    QDialog(parent),
    ui(new Ui::StadiumEditPage)
{
    ui->setupUi(this);

    this->ui->capacityInput->setValidator(new QIntValidator());
    this->ui->openedInput->setValidator(new QIntValidator());

    this->stadium = stadium;

    this->ui->nameInput->setText(stadium->name);
    this->ui->capacityInput->setText(QString::number(stadium->capacity));
    this->ui->locationInput->setText(stadium->location);
    this->ui->grassCheckbox->setChecked(stadium->hasGrass);
    this->ui->teamInput->setText(stadium->team);
    this->ui->openedInput->setText(QString::number(stadium->opened));
    this->ui->americanCheckbox->setChecked(stadium->isAmerican);

    this->edit = true;
}

StadiumEditPage::StadiumEditPage(QWidget *parent, bool *selectedStadiums, Stadium *stadiums) :
    QDialog(parent),
    ui(new Ui::StadiumEditPage)
{
    ui->setupUi(this);

    this->ui->capacityInput->setValidator(new QIntValidator());
    this->ui->openedInput->setValidator(new QIntValidator());

    this->selectedStadiums = selectedStadiums;
    this->stadiums = stadiums;
    this->edit = false;
}

StadiumEditPage::~StadiumEditPage()
{
    delete ui;
}

void StadiumEditPage::on_cancelBtn_clicked()
{
    this->close();
}


void StadiumEditPage::on_saveBtn_clicked()
{
    if(this->edit)
    {
        stadium->name = this->ui->nameInput->text();
        stadium->capacity = this->ui->capacityInput->text().toInt();
        stadium->location = this->ui->locationInput->text();
        stadium->hasGrass = this->ui->grassCheckbox->isChecked();
        stadium->team = this->ui->teamInput->text();
        stadium->opened = this->ui->openedInput->text().toInt();
        stadium->isAmerican = this->ui->americanCheckbox->isChecked();
    }
    else
    {
        for(int i = 0; i < 30; i ++)
        {
            Stadium *stadium = &this->stadiums[i];

            if((this->ui->nameInput->text().isEmpty() ||
                stadium->name == this->ui->nameInput->text()))
            {

            }
        }
    }

    this->close();
}

