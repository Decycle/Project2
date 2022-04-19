#include "stadiumeditpage.h"
#include "ui_stadiumeditpage.h"

StadiumEditPage::StadiumEditPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StadiumEditPage)
{
    ui->setupUi(this);
}

StadiumEditPage::~StadiumEditPage()
{
    delete ui;
}
