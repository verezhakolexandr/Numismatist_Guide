#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coinstable.h"
#include "coincollectorstable.h"

#include "dbmanager.h"
#include "sqlitedbmanager.h"

MainWindow::MainWindow(DBManager* dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    db(dbManager)
{
    ui->setupUi(this);

    db->connectToDataBase();

//    Coin coin;
//    coin.setCountry("Ukraine");
//    coin.setDenomination(5);
//    coin.setFeatures("None");
//    coin.setValue(100);
//    coin.setYear(1928);
//    db->insertIntoCoinsTable(coin);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    CoinsTable dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    CoinCollectorsTable dialog;
    dialog.setModal(true);
    dialog.exec();
}

