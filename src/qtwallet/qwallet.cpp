#include "qwallet.h"
#include "wallet/api/wallet_api.h"

QWallet::QWallet()
{

}


status_t QWallet::initWallet(const std::string& path, const std::string& password, const std::string& daemonAddress){

    auto language = "english";
    Safex::NetworkType nettype = Safex::NetworkType::TESTNET;


    auto manager = Safex::WalletManagerFactory::getWalletManager();
    if (manager->walletExists(path)) {
        return std::make_pair(1, "Wallet exists");
    }

    wallet_ = manager->createWallet(path, password, language, nettype);

    if (!wallet_) {
        return std::make_pair(1, "Could not create the wallet!");
    }

    if (!wallet_->errorString().empty()) {
        return std::make_pair(1, "Error while creating wallet: " + wallet_->errorString());
    }

    if (!wallet_->init(daemonAddress)) {
        return std::make_pair(1, "Could not connect to daemon!");
    }

    wallet_->setTrustedDaemon(true);
    wallet_->startRefresh();

    return std::make_pair(0, "Wallet created");

}
