#ifndef TABLEVIEWPAGE_H
#define TABLEVIEWPAGE_H

#include "stadium.h"
#include "stadiummaster.h"

#include <QDialog>

namespace Ui {
class TableViewPage;
}

class TableViewPage : public QDialog
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    explicit TableViewPage(QWidget *parent = nullptr);
    ~TableViewPage();

private slots:
    void on_returnBtn_clicked();

private:
    Ui::TableViewPage *ui;
};

#endif // TABLEVIEWPAGE_H
