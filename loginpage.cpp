#include "loginpage.h"
#include "ui_loginpage.h"

#include <QDebug>

/**********************************************************
* Method LoginPage(): Class LoginPage
*_________________________________________________________
* This method create a default constructor
*_________________________________________________________
* PRE-CONDITIONS
*      qwidget  mainwindow
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
LoginPage::LoginPage(QWidget *parent, MainWindow *mainWindow) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->mainWindow = mainWindow;
}

/**********************************************************
* Method ~LoginPage(): Class LoginPage
*_________________________________________________________
* This method delete a default constructor
*_________________________________________________________
* PRE-CONDITIONS
*      none
*
* POST-CONDITIONS
*     delete a default object
***********************************************************/
LoginPage::~LoginPage()
{
    delete ui;
}

/**********************************************************
* Method on_loginBtn_clicked(): Class LoginPage
*_________________________________________________________
* This method will start action with input user name and
* password
*_________________________________________________________
* PRE-CONDITIONS
*
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
void LoginPage::on_loginBtn_clicked()
{
    if(this->ui->password->text() == "admin" &&
       this->ui->username->text() == "admin")
    {
        this->ui->messageLabel->setText("Logged In!");
        this->mainWindow->login();
        this->close();
    }
    else
    {
        this->ui->messageLabel->setText("Wrong Password or Username");
    }
}

/**********************************************************
* Method on_cancelBtn_clicked(): Class LoginPage
*_________________________________________________________
* This method will close window when click on cancel button
*_________________________________________________________
* PRE-CONDITIONS
*
*
* POST-CONDITIONS
*     close window
***********************************************************/
void LoginPage::on_cancelBtn_clicked()
{
    this->close();
}

