#include "mainwindow.h"
#include "./ui_mainwindow.h"
<<<<<<< HEAD
#include "wallet/api/wallet_api.h"
=======
>>>>>>> Added Qt wallet to build system

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_argc(argc),m_argv(argv)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init_wallet(){


  cryptonote::simple_wallet::init_from_qt(m_argc,m_argv, m_sw);
}
