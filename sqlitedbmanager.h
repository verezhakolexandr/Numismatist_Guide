#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

#include "dbmanager.h"
#include "coincollector.h"
#include "coin.h"

#define DATABASE_HOSTNAME                                                   "Database"
#define DATABASE_NAME                                                       "DBProj.db"

#define COLLECTORS_TABLE_NAME                                               "CoinCollectorsTable"
#define COLLECTORS_COUNTRY                                                  "Country"
#define COLLECTORS_NAME                                                     "Name"
#define COLLECTORS_PHONE_NUMBER                                             "PhoneNumber"
#define COLLECTORS_NUMBER_OF_RARE_COINS                                     "NumberOfRareCoins"

#define COINS_TABLE_NAME                                                    "CoinsTable"
#define COINS_COUNTRY                                                       "Country"
#define COINS_FEATURES                                                      "Features"
#define COINS_DENOMINATION                                                  "Denomination"
#define COINS_YEAR                                                          "Year"
#define COINS_VALUE                                                         "Value"

class SQLiteDBManager : public DBManager {

public:
    static SQLiteDBManager* getInstance();


    void connectToDataBase();
    QSqlDatabase getDB();
    bool insertIntoCollectorsTable(const CoinCollector &collectorData);
    bool insertIntoCoinsTable(const Coin &coinData);
//    bool checkLogPass(QString login, QString passwordHash);
//    QString hashPassword(QString password);

private:
    QSqlDatabase    db;

private:

    static SQLiteDBManager* instance;

    SQLiteDBManager();

    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTables();

};



#endif // DATABASE_H
