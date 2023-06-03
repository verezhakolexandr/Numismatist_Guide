#include "addcoin.h"
#include "ui_addcoin.h"
#include "sqlitedbmanager.h"
#include "dbmanager.h"

AddCoin::AddCoin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCoin)
{
    ui->setupUi(this);
}

AddCoin::~AddCoin()
{
    delete ui;
}

void AddCoin::on_pushButton_clicked()
{
    Coin coin;
    coin.setCountry(ui->coinCountry->text());
    coin.setDenomination(ui->coinDenomination->text().toInt());
    coin.setFeatures(ui->coinFeatures->text());
    coin.setValue(ui->coinValue->text().toInt());
    coin.setYear(ui->coinYear->text().toInt());
    DBManager *db = SQLiteDBManager::getInstance();
    if(db->insertIntoCoinsTable(coin)) {
        close();
    }
}

