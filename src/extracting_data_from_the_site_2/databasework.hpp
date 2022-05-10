#ifndef DATABASEWORK_HPP
#define DATABASEWORK_HPP

#include<QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

class DataBaseWork {
public:
    bool connection(const QString &name, const QString &host, const QString &dbname, const QString password);
 bool insert(const QString& date,const QString& solar_radiation_intensity,const QString& kp, const QString& ap);
private:
    QSqlDatabase db;

};

#endif // DATABASEWORK_HPP
