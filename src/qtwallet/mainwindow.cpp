#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "wallet/api/wallet_api.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init_wallet(){

  auto path = "/home/igor/workarea/qt_wallet_test/test";
  std::string password = ui->lineEdit_2->text().toStdString();
  auto language = "english";
  auto nettype = true;
  auto daemonAddress = "127.0.0.1:29393";

  auto manager = Safex::WalletManagerFactory::getWalletManager();
  if (manager->walletExists(path)) {
      return;
  }

  auto wallet_ = manager->createWallet(path, password, language,nettype);

  if (!wallet_) {
      return;
  }

  if (!wallet_->errorString().empty()) {
      return;
  }

  if (!wallet_->init(daemonAddress)) {
      return;
  }

  wallet_->setTrustedDaemon(true);
  wallet_->startRefresh();
  return;
}
