#include "stadiumeditpage.h"
#include "ui_stadiumeditpage.h"
#include "appcontroller.h"
#include <QIntValidator>

/************
 * CONSTRUCTOR *
 * **********/

/*************************************************
 * Method StadiumEditPage(): Class StadiumEditPage
 * _______________________________________________
 * COnstructor for StadiumEditPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Initalized the StadiumEditPage page.
 * ***********************************************/
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

/*************************************************
 * Method StadiumEditPage(): Class StadiumEditPage
 * _______________________________________________
 * Overload Constructor for StadiumEditPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Initalized the StadiumEditPage page.
 * ***********************************************/
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

/****************
 * DECONSTRUCTOR *
 * **************/

/*************************************************
 * Method ~StadiumEditPage(): Class StadiumEditPage
 * _______________________________________________
 * Deconstructor for StadiumEditPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Deleted the StadiumEditPage page.
 * ***********************************************/
StadiumEditPage::~StadiumEditPage()
{
    delete ui;
}

/*************************************************
 * Method on_cancelBtn_clicked(): Class StadiumEditPage
 * _______________________________________________
 * Overload Constructor for StadiumEditPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Deleted the StadiumEditPage page.
 * ***********************************************/
void StadiumEditPage::on_cancelBtn_clicked()
{
    this->close();
}


/*************************************************
 * Method on_saveButton_clicked(): Class StadiumEditPage
 * _______________________________________________
 * Overload Constructor for StadiumEditPage class.
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * int index
 * POST-CONDITIONS:
 * Deleted the StadiumEditPage page.
 * ***********************************************/
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

        for(int i = 0; i < AppController::StadiumCount; i ++)
        {
            Stadium *stadium = AppController::Stadiums[i];

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

