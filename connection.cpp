#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2A27");//inserer le nom de la source de données ODBC
db.setUserName("salma");//inserer nom de l'utilisateur
db.setPassword("salma");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
