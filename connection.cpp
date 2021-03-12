#include "connection.h"

Connection::Connection()
{

}

bool Connection::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_project");//inserer le nom de la source de données ODBC
db.setUserName("oubeid");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
