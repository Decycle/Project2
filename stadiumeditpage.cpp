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

    this->ui->grassCheckbox->setTristate(false);
    this->ui->americanCheckbox->setTristate(false);

    this->edit = true;
}

StadiumEditPage::StadiumEditPage(QWidget *parent, MainWindow *mainWindow) :
    QDialog(parent),
    ui(new Ui::StadiumEditPage)
{
    ui->setupUi(this);

    this->ui->capacityInput->setValidator(new QIntValidator());
    this->ui->openedInput->setValidator(new QIntValidator());

    this->ui->grassCheckbox->setCheckState(Qt::PartiallyChecked);
    this->ui->americanCheckbox->setCheckState(Qt::PartiallyChecked);

    this->mainWindow = mainWindow;
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
        this->mainWindow->clearSelection();

        for(int i = 0; i < 30; i ++)
        {
            Stadium *stadium = this->mainWindow->getStadiums()[i];

            if((this->ui->nameInput->text().isEmpty() ||
                stadium->name == this->ui->nameInput->text()) &&
                (this->ui->capacityInput->text().isEmpty() ||
                stadium->capacity == this->ui->capacityInput->text().toInt()) &&
                (this->ui->locationInput->text().isEmpty() ||
                stadium->location == this->ui->locationInput->text()) &&
                (this->ui->grassCheckbox->isChecked() == stadium->hasGrass ||
                 this->ui->grassCheckbox->checkState() == Qt::PartiallyChecked) &&
                (this->ui->teamInput->text().isEmpty() ||
                stadium->team == this->ui->teamInput->text()) &&
                (this->ui->openedInput->text().isEmpty() ||
                stadium->opened == this->ui->openedInput->text().toInt()) &&
                (this->ui->americanCheckbox->isChecked() == stadium->isAmerican ||
                 this->ui->americanCheckbox->checkState() == Qt::PartiallyChecked))
            {
                this->mainWindow->selectStadium(i);
            }
        }
    }

    this->close();
}

