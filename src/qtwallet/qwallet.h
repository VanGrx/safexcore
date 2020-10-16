#ifndef QWALLET_H
#define QWALLET_H

#include <string>
#include "wallet/api/wallet_api.h"

typedef std::pair<int, std::string> status_t;

class QWallet
{
public:
    QWallet();

    Safex::Wallet* wallet_;

    status_t initWallet(const std::string& path, const std::string& password, const std::string& daemonAddress);
    status_t openWallet(const std::string& path, const std::string& password, const std::string& daemonAddress);

};

#endif // QWALLET_H
