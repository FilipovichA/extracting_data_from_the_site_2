#include "filework.hpp"
#include "QSqlQuery"
FileWork::FileWork(QObject *parent) : QObject(parent)
{
manager = new QNetworkAccessManager();
connect(manager, &QNetworkAccessManager::finished, this, &FileWork::onResult);
}
void FileWork::getData()
{
    QUrl url("https://services.swpc.noaa.gov/text/27-day-outlook.txt"); // URL, к которому будем получать данные
    QNetworkRequest request;    // Отправляемый запрос
    request.setUrl(url);        // Устанавлвиваем URL в запрос
    manager->get(request);      // Выполняем запрос
}
void FileWork::onResult(QNetworkReply *reply)
{DataBaseWork qaz;
    const QString fname = "/home/sasha/extracting_data_from_the_site_2/file.txt";
    QStringList lines;
    QString line;
   qaz.connection("sasha","localhost","dbeditor","2882");
    // Если в процесе получения данных произошла ошибка
    if(reply->error()){
        // Сообщаем об этом и показываем информацию об ошибках
        qDebug() << "ERROR";
        qDebug() << reply->errorString();
    } else {
        // В противном случае создаём объект для работы с файлом
        QFile *file = new QFile(fname);
        QFile inputFile(fname);
        QTextStream edit(&inputFile);
         //Создаём файл или открываем его на перезапись ...
        if(file->open(QFile::WriteOnly)){
            file->write(reply->readAll());  // ... и записываем всю информацию со страницы в файл
            file->close();                 // закрываем файл
        reply->readAll();
        qDebug() << "Downloading is completed";
        //emit onReady(); // Посылаем сигнал о завершении получения файла
        }
        if (inputFile.open(QIODevice::ReadWrite))
        {
        while(!edit.atEnd())
          lines.append(edit.readLine());
        }
        inputFile.close();
        {
       if (inputFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            for(int i=11; i<lines.size()-1; i++)
               {
                edit<<lines[i]+"\n";
            }
       }
        inputFile.close();
        }
        if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
           qDebug()<<"error";
        }
        else{
          QSqlQuery qw;
          qw.prepare("Delete From qw_pgfu.forecast_indexes_3days");
          if(!qw.exec()){
              qDebug()<<"failed";
          }
          else
          {
              qDebug()<<"Successfully";
          }
            while(!edit.atEnd()){
                QString linel=edit.readLine();
                QStringList listl;
                  linel.replace("          ","    ");
                   listl=linel.split("    ");
 qaz.insert(listl.at(0),listl.at(1),listl.at(2),listl.at(3));
            }
            inputFile.remove(fname);
        }
        }
    }

