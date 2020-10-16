#ifndef QOPENWALLETTASK_H
#define QOPENWALLETTASK_H

#include <QThread>
#include <string>
#include "wallet/api/wallet_api.h"

class QOpenWalletTask : public QThread
{
    Q_OBJECT

public:
    QOpenWalletTask(){};

    QOpenWalletTask(Safex::Wallet* wallet_, const std::string& path_, const std::string& password_, const std::string& daemonAddress_):wallet{wallet_}, path{path_}, password{password_}, daemonAddress{daemonAddress_}{};

    void run();
    // Define signal:
signals:
    void progressChanged(QString info);


private:
    Safex::Wallet* wallet;
    std::string path;
    std::string password;
    std::string daemonAddress;

};

#endif // QOPENWALLETTASK_H
