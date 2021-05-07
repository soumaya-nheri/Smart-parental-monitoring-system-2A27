#include "notifications.h"
#include <QSystemTrayIcon>
#include<QString>
Notifications::Notifications()
{

}

void Notifications::notifications_ecran()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

//    notifyIcon->setIcon(QIcon(":/new/prefix1/download.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des article ","article presque fini ",QSystemTrayIcon::Information,15000);
}
