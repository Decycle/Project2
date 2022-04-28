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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void login();
    void selectStadium(int i);
    void clearSelection();
    Stadium** getStadiums();
private slots:
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
    Ui::MainWindow *ui;
    CanvasManager *canvas;
    StadiumMaster *stadiumMaster;

};
#endif // MAINWINDOW_H
