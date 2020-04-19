#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "qwallet.h"
#include "./ui_stackedwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StackedWidget; }
QT_END_NAMESPACE

class StackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackedWidget(QWidget *parent = nullptr);
    ~StackedWidget();

public slots:
    void initWallet();

private:
    Ui::StackedWidget *ui;
    QWallet mQWallet;
};

#endif // STACKEDWIDGET_H
