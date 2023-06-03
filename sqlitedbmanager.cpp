#include "sqlitedbmanager.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QCryptographicHash>
#include <QSqlRecord>
#include <QMessageBox>

SQLiteDBManager* SQLiteDBManager::instance = nullptr;

SQLiteDBManager::SQLiteDBManager(){

}

SQLiteDBManager* SQLiteDBManager::getInstance()
{
    if(instance == nullptr){
        instance = new SQLiteDBManager();
    }
    return instance;
}

void SQLiteDBManager::connectToDataBase()
{

    if(QFile(DATABASE_NAME).exists()){
        this->openDataBase();
    } else {
        this->restoreDataBase();
    }
}

QSqlDatabase SQLiteDBManager::getDB()
{
    return db;
}


bool SQLiteDBManager::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTables()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

bool SQLiteDBManager::openDataBase()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else
        return false;
}

void SQLiteDBManager::closeDataBase()
{
    db.close();
}


bool SQLiteDBManager::createTables()
{

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " COLLECTORS_TABLE_NAME " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    COLLECTORS_NAME                         " TEXT              NOT NULL,"
                    COLLECTORS_COUNTRY                      " TEXT              NOT NULL,"
                    COLLECTORS_NUMBER_OF_RARE_COINS         " TEXT              NOT NULL,"
                    COLLECTORS_PHONE_NUMBER                 " TEXT              NOT NULL"
                    " )"
                    )){
        qDebug() << "DataBase: error of create " << COLLECTORS_TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    } else {
        if(!query.exec( "CREATE TABLE " COINS_TABLE_NAME " ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        COINS_COUNTRY                               " TEXT          NOT NULL, "
                        COINS_DENOMINATION                          " TEXT          NOT NULL, "
                        COINS_VALUE                                 " TEXT          NOT NULL, "
                        COINS_FEATURES                              " TEXT          DEFAULT 'none', "
                        COINS_YEAR                                  " TEXT          NOT NULL "
                        " )"
                    )){
            qDebug() << "DataBase: error of create " << COINS_TABLE_NAME;
            qDebug() << query.lastError().text();
            return false;
        } else {
        return true;
        }

}
}

bool SQLiteDBManager::insertIntoCollectorsTable(const CoinCollector &collectorData)
{

    QSqlQuery query;
        query.prepare("INSERT INTO " COLLECTORS_TABLE_NAME " ( " COLLECTORS_NAME ", "
                      COLLECTORS_COUNTRY ", "
                      COLLECTORS_NUMBER_OF_RARE_COINS ", "
                      COLLECTORS_PHONE_NUMBER " ) "
                                            "VALUES (:Name, :Country, :NumberOfRareCoins, :PhoneNumber)");
        query.bindValue(":Name",                        collectorData.getName());
        query.bindValue(":Country",                     collectorData.getCountry());
        query.bindValue(":NumberOfRareCoins",           collectorData.getNumberOfRareCoins());
        query.bindValue(":PhoneNumber",                 collectorData.getPhoneNumber());


    if(!query.exec()){
        qDebug() << "error insert into " COLLECTORS_TABLE_NAME " table";
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}

bool SQLiteDBManager::insertIntoCoinsTable(const Coin &coinData)
{

    QSqlQuery query;
        query.prepare("INSERT INTO " COINS_TABLE_NAME " ( " COINS_COUNTRY ", "
                      COINS_DENOMINATION ", "
                      COINS_VALUE ", "
                      COINS_FEATURES " , "
                      COINS_YEAR " ) "
                                            "VALUES (:Country, :Denomination, :Value, :Features, :Year)");
        query.bindValue(":Country",                             coinData.getCountry());
        query.bindValue(":Denomination",                        coinData.getDenomination());
        query.bindValue(":Value",                               coinData.getValue());
        query.bindValue(":Features",                            coinData.getFeatures());
        query.bindValue(":Year",                                coinData.getYear());


    if(!query.exec()){
        qDebug() << "error insert into " COLLECTORS_TABLE_NAME " table";
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}


//bool SQLiteDBManager::bookRoom(const Room &roomsData) {
//    QSqlQuery query;
//    query.prepare("UPDATE " ROOMS_TABLE_NAME
//                  " SET " ROOMS_CLIENT_NAME " = :clientName , "
//                  ROOMS_CLIENT_PHONE " = :clientPhone , "
//                  ROOMS_TIME " = :time WHERE " ROOMS_NUMBER " = :number ");

//    query.bindValue(":clientName",      roomsData.getClientName());
//    query.bindValue(":clientPhone",     roomsData.getClientPhone());
//    query.bindValue(":time",            roomsData.getTime());
//    query.bindValue(":number",          roomsData.getNumber());

//    if(!query.exec()){
//        qDebug() << "error update rooms table";
//        qDebug() << query.lastError().text();
//        qDebug() << query.lastQuery();

//        return false;
//    } else
//        return true;
//}


//QString SQLiteDBManager::hashPassword(QString password) {
//    QString hash;
//    QByteArray hashpassword(password.toStdString().c_str());
//    hash = QCryptographicHash::hash(hashpassword, QCryptographicHash::Sha256).toHex();
//    return hash;
//}
