#include "modifystadium.h"
#include "ui_modifystadium.h"

ModifyStadium::ModifyStadium(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyStadium)
{
    ui->setupUi(this);
}

ModifyStadium::~ModifyStadium()
{
    delete ui;
}
