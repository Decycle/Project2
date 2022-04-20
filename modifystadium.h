#ifndef MODIFYSTADIUM_H
#define MODIFYSTADIUM_H

#include <QDialog>

namespace Ui {
class ModifyStadium;
}

class ModifyStadium : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyStadium(QWidget *parent = nullptr);
    ~ModifyStadium();

private:
    Ui::ModifyStadium *ui;
};

#endif // MODIFYSTADIUM_H
