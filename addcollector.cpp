#include "addcollector.h"
#include "ui_addcollector.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"

AddCollector::AddCollector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCollector)
{
    ui->setupUi(this);
}

AddCollector::~AddCollector()
{
    delete ui;
}

void AddCollector::on_pushButton_clicked()
{
    CoinCollector collector;
    collector.setName(ui->collectorsName->text());
    collector.setCountry(ui->collectorsCountry->text());
    collector.setNumberOfRareCoins(ui->collectorsNumberOfRareCoins->text().toInt());
    collector.setPhoneNumber(ui->collectorsPhoneNumber->text());
    DBManager *db = SQLiteDBManager::getInstance();
    if(db->insertIntoCollectorsTable(collector)) {
        close();
    }

}

