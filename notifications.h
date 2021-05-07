#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include <QSystemTrayIcon>
#include<QString>

class Notifications
{
public:
    Notifications();
    void notifications_ajouterPortes();
    void notifications_ajouterElectromenage();
    void notifications_supprimerPortes();
    void notifications_supprimerElectromenage();
    void notifications_ecran();




};

#endif // NOTIFICATIONS_H
