#ifndef COIN_H
#define COIN_H

#include <QString>

class Coin
{
    QString country;
    QString features;
    int denomination;
    int year;
    int value;
public:
    QString getCountry() const{
        return this->country;
    }
    void setCountry(QString country) {
        this->country = country;
    }
    QString getFeatures() const{
        return this->features;
    }
    void setFeatures(QString features){
        this->features = features;
    }
    int getDenomination() const{
        return this->denomination;
    }
    void setDenomination(int denomination) {
        this->denomination = denomination;
    }
    int getYear() const{
        return this->year;
    }
    void setYear(int year) {
        this->year = year;
    }
    int getValue() const{
        return this->value;
    }
    void setValue(int value) {
        this->value = value;
    }
    Coin();
};

#endif // COIN_H
