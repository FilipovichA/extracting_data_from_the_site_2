#include <QCoreApplication>
#include "filework.hpp"


int main(int argc, char *argv[])
{

    QCoreApplication app( argc, argv );

FileWork qwe;
qwe.getData();
    return( app.exec() );

}
