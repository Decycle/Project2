#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stadium.h"
#include "canvasmanager.h"
#include "stadiummaster.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**************
     ** MUTATORS **
     **************/
    void login();
    void selectStadium(int i);
    void clearSelection();

    /***************
    ** ACCESSORS **
    ***************/
    Stadium** getStadiums();
private slots:

    /**************
     ** MUTATORS **
     **************/
    void on_startPathBtn_clicked();
    void on_randomStadiumBtn_clicked();
    void on_loginBtn_clicked();
    void on_clearAllBtn_clicked();
    void on_editStadiumBtn_clicked();
    void on_showSelectedStadiumsBtn_clicked();
    void on_searchStadiumsBtn_clicked();
    void on_selectAllBtn_clicked();
    void on_tableViewBtn_clicked();
    void on_newStadiumBtn_clicked();
    void on_newPathBtn_clicked();
    void on_startTripBtn_clicked();
    void on_showNameBtn_clicked();
    void on_editSouvenirBtn_clicked();

private:
    Ui::MainWindow *ui;             // IN/OUT - ui
    CanvasManager *canvas;          // IN/OUT - canvas
    StadiumMaster *stadiumMaster;   // IN/OUT - stadiummaster

};
#endif // MAINWINDOW_H
