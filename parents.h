#ifndef PARENTS_H
#define PARENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class parents
{
public:
    parents();
    parents(QString,QString,int,QString,QString,QString);
    QString get_NOM_DE_FAMILLE();
    QString get_PRENOM_RES();
    int get_CIN();
    QString get_EMAIL_RESP() ;
    QString get_PASSWORD() ;
    QString get_PAYS() ;



     bool ajouter();
   bool modifier(QString,QString,int,QString,QString,QString);
   QSqlQueryModel * afficher();
   bool supprimer(int);
   QSqlQueryModel * trier();
    QSqlQueryModel * recherche(QString var);
   void on_pB_email_clicked();
   QSqlQueryModel * afficher_email();




private:
    int CIN;
    QString NOM_DE_FAMILLE,PRENOM_RES,EMAIL_RESP,PASSWORD,PAYS;

};

#endif // PARENTS_H
