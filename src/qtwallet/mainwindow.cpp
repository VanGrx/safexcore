#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_argc(argc)
{
    m_argv = (char**)malloc(argc*sizeof(char*));

    for(int i=0;i<argc;i++){
        m_argv[i] = (char*)malloc(20*sizeof(char));
        m_argv[i] = argv[i];
    }

    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
    for(int i=0; i<m_argc; i++)
      free(m_argv[i]);
    free(m_argv);
}


void MainWindow::init_wallet(){

  //Select network
//  m_argc++;
//  m_argv = (char**)realloc(m_argv,m_argc*sizeof(char*));
//  m_argv[m_argc-1] = (char*)malloc(20*sizeof(char));
//  strcpy(m_argv[m_argc-1], std::string{"--testnet"}.c_str());

  //Open wallet file
  m_argc++;
  m_argv = (char**)realloc(m_argv,m_argc*sizeof(char*));
  m_argv[m_argc-1] = (char*)malloc(20*sizeof(char));
  strcpy(m_argv[m_argc-1], std::string{"--wallet-file"}.c_str());
  m_argc++;
  m_argv = (char**)realloc(m_argv,m_argc*sizeof(char*));
  m_argv[m_argc-1] = (char*)malloc(100*sizeof(char));
  strcpy(m_argv[m_argc-1], std::string{"/home/vangrx/workarea/safexcore/build/debug/bin/lago"}.c_str());

  //Password
  m_argc++;
  m_argv = (char**)realloc(m_argv,m_argc*sizeof(char*));
  m_argv[m_argc-1] = (char*)malloc(20*sizeof(char));
  strcpy(m_argv[m_argc-1], std::string{"--password"}.c_str());

  m_argc++;
  m_argv = (char**)realloc(m_argv,m_argc*sizeof(char*));
  m_argv[m_argc-1] = (char*)malloc(20*sizeof(char));
  strcpy(m_argv[m_argc-1], std::string{"x"}.c_str());

  cryptonote::simple_wallet::init_from_qt(m_argc,m_argv, m_sw);
}
