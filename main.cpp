#include "MainWindow.h"
#include <QApplication>
#include "include/ShopSystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ShopSystem::getInstance()->loadAllData();

    MainWindow w;
    w.show();

    int exitCode = a.exec();
    ShopSystem::getInstance()->saveAllData();

    return exitCode;
}
