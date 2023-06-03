#ifndef COINCOLLECTOR_H
#define COINCOLLECTOR_H

#include <QString>

class CoinCollector
{
    QString country;
    QString name;
    QString phoneNumber;
    int numberOfRareCoins;
public:
    QString getCountry() const{
        return this->country;
    }
    void setCountry(QString country) {
        this->country = country;
    }
    QString getName() const{
        return this->name;
    }
    void setName(QString name) {
        this->name = name;
    }
    QString getPhoneNumber() const{
        return this->phoneNumber;
    }
    void setPhoneNumber(QString phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    int getNumberOfRareCoins() const{
        return this->numberOfRareCoins;
    }
    void setNumberOfRareCoins(int numberOfRareCoins) {
        this->numberOfRareCoins = numberOfRareCoins;
    }
    CoinCollector();
};

#endif // COINCOLLECTOR_H
