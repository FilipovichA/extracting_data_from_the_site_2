#include "databasework.hpp"
bool DataBaseWork::connection(const QString &name, const QString &host, const QString &dbname, const QString password)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName(name);
    db.setHostName(host);
    db.setDatabaseName(dbname);
    db.setPassword(password);

    if(!db.open())
    {
        qDebug()<<"bd not open";
        return false;
    }
    else
    {
        qDebug()<<"bd is open";
        return true;
    }}


bool DataBaseWork::insert(const QString& date_,const QString& solar_radiation_intensity,const QString& kp, const QString& ap)
{QSqlQuery query;
    QString a;
    a="INSERT INTO qw_pgfu.forecast_indexes_3days(date_,solar_radiation_intensity,kp,ap) Values('"+date_+"',"+solar_radiation_intensity+','+kp+','+ap+")";
    query.prepare(a);
    qDebug()<<a;
    if(!query.exec()){
        qDebug()<<"failed";
        return false;
    }
    else
    {
        qDebug()<<"Successfully";
        return true;
    }
}
