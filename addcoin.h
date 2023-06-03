#ifndef ADDCOIN_H
#define ADDCOIN_H

#include <QDialog>

namespace Ui {
class AddCoin;
}

class AddCoin : public QDialog
{
    Q_OBJECT

public:
    explicit AddCoin(QWidget *parent = nullptr);
    ~AddCoin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddCoin *ui;
};

#endif // ADDCOIN_H
