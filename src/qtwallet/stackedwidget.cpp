#include "stackedwidget.h"

StackedWidget::StackedWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::StackedWidget)
{
    ui->setupUi(this);

    this->setCurrentIndex(WIDGET_LOGIN);

}

StackedWidget::~StackedWidget()
{
    delete ui;
}

void StackedWidget::initWallet(){

    auto path = "/home/igor/workarea/qt_wallet_test/test2";
    std::string password = ui->passwordEdit->text().toStdString();
    auto daemonAddress = "127.0.0.1:29393";

    auto result = mQWallet.initWallet(path,password,daemonAddress);

    if(result.first)
        ui->statusLabel->setStyleSheet("QLabel { color : red; }");
    else
        ui->statusLabel->setStyleSheet("QLabel { color : green; }");

    ui->statusLabel->setText(result.second.c_str());



    return;
}


void StackedWidget::openWallet(){

    this->setCurrentIndex(WIDGET_STATUS_BAR);

    auto path = "/home/igor/workarea/testnet-global/wallet_01.bin";
    std::string password = ui->passwordEdit->text().toStdString();
    auto daemonAddress = "127.0.0.1:29393";

    auto result = mQWallet.openWallet(path,password,daemonAddress);

    if(result.first)
        ui->statusLabel->setStyleSheet("QLabel { color : red; }");
    else
        ui->statusLabel->setStyleSheet("QLabel { color : green; }");

    ui->statusLabel->setText(result.second.c_str());



    return;
}
