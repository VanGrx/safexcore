#include "stackedwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  StackedWidget w;
  w.show();
  return a.exec();
}
