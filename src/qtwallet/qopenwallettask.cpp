#include "qopenwallettask.h"


void QOpenWalletTask::run() {
    auto language = "english";
    Safex::NetworkType nettype = Safex::NetworkType::TESTNET;

    auto manager = Safex::WalletManagerFactory::getWalletManager();
    if (!manager->walletExists(path)) {
        emit progressChanged("Wallet doeesn't exist");
        return;
    }

    wallet = manager->openWallet(path, password, nettype);

    if (!wallet) {
        emit progressChanged("Could not open the wallet!");
        return;
    }

    if (!wallet->errorString().empty()) {
        QString errorStr("Error while opening wallet: ");
        errorStr.append(wallet->errorString().c_str());
        emit progressChanged(errorStr);
        return;
    }

    if (!wallet->init(daemonAddress)) {
        emit progressChanged("Could not connect to daemon!");
        return;
    }

    //set refresh height as latest block wallet has seen - 1 day
    uint64_t currentHeight = wallet->blockChainHeight();
    wallet->setRefreshFromBlockHeight(currentHeight - 720 > 0 ? currentHeight - 720 : 0);

    wallet->setTrustedDaemon(true);
    wallet->startRefresh();


    emit progressChanged("Wallet opened");
    return;
}
