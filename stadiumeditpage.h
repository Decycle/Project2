#ifndef STADIUMEDITPAGE_H
#define STADIUMEDITPAGE_H

#include <QDialog>
#include "stadium.h"
#include "mainwindow.h"

/***********************************************************
* Class StadiumEditPage
*_________________________________________________________
* This class will create the edit page for stadium
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   This class will create the edit page for stadium
***********************************************************/
namespace Ui {
class StadiumEditPage;
}

class StadiumEditPage : public QDialog
{
    Q_OBJECT

public:

    explicit StadiumEditPage(QWidget *parent = nullptr, Stadium *stadium = nullptr); // edit the stadium
    explicit StadiumEditPage(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr); // find the stadium
    ~StadiumEditPage(); // Destructor

private slots:
    void on_cancelBtn_clicked(); // create the cancel button
    void on_saveBtn_clicked(); // create the save button

private:
    Ui::StadiumEditPage *ui;
    Stadium *stadium;
    MainWindow *mainWindow;
    bool edit;
};

#endif // STADIUMEDITPAGE_H
