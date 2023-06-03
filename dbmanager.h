#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase>
#include <QVariantList>
#include "coin.h"
#include "coincollector.h"

class DBManager
{
public:
    DBManager();

    virtual void connectToDataBase() = 0;
    virtual QSqlDatabase getDB() = 0;
    virtual bool insertIntoCollectorsTable(const CoinCollector &collectorData) = 0;
    virtual bool insertIntoCoinsTable(const Coin &coinData) = 0;
};

#endif // DBMANAGER_H
