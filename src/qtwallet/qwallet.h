#ifndef QWALLET_H
#define QWALLET_H

#include <string>

typedef std::pair<int, std::string> status_t;

class QWallet
{
public:
    QWallet();

    status_t initWallet(const std::string& path, const std::string& password, const std::string& daemonAddress);

};

#endif // QWALLET_H
