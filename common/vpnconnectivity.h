#ifndef VPNCONNECTIVITY_H
#define VPNCONNECTIVITY_H

#include <QObject>

class vpnConnectivity : public QObject
{
        Q_OBJECT
    public:
        explicit vpnConnectivity(QObject *parent = 0);
        static bool online();

    signals:

    public slots:

};

#endif // VPNCONNECTIVITY_H
