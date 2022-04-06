#include "loginpage.h"
#include "ui_loginpage.h"

#include <QDebug>

LoginPage::LoginPage(QWidget *parent, MainWindow *mainWindow) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->mainWindow = mainWindow;
}

LoginPage::~LoginPage()
{
    delete ui;
}

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


void LoginPage::on_cancelBtn_clicked()
{
    this->close();
}

