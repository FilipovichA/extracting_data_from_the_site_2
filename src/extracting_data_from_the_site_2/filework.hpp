#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include<QSqlDatabase>
#include <databasework.hpp>

class FileWork: public QObject
{
    Q_OBJECT
public:
    explicit FileWork(QObject *parent = nullptr);



public slots:
    void getData();     // Метод инициализации запроса на получение данных
    void onResult(QNetworkReply *reply);    // Слот обработки ответа о полученных данных

private:
    QNetworkAccessManager *manager; // менеджер сетевого доступа
     FileWork *downloader;
};




