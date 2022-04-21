#ifndef STADIUMEDITPAGE_H
#define STADIUMEDITPAGE_H

#include <QDialog>
#include "stadium.h"

namespace Ui {
class StadiumEditPage;
}

class StadiumEditPage : public QDialog
{
    Q_OBJECT

public:
    explicit StadiumEditPage(QWidget *parent = nullptr, Stadium *stadium = nullptr);
    explicit StadiumEditPage(QWidget *parent = nullptr, bool *selectedStadiums = nullptr);
    ~StadiumEditPage();

private slots:
    void on_cancelBtn_clicked();
    void on_saveBtn_clicked();

private:
    Ui::StadiumEditPage *ui;
    Stadium *stadium;
    bool *selectedStadiums;
    bool edit;
};

#endif // STADIUMEDITPAGE_H
