#include "MainWindow.h"
#include "IntroWidget.h"
#include <QApplication>
#include "include/ShopSystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShopSystem::getInstance()->loadAllData();
    MainWindow w;
    IntroWidget intro;
    QObject::connect(&intro, &IntroWidget::enterPressed, [&]() {
        if (intro.isFullScreen()) {
            w.showFullScreen();
        }
        else if (intro.isMaximized()) {
            w.showMaximized();
        }
        else {
            w.show();
        }

        intro.close();
    });
    intro.show();
    int exitCode = a.exec();
    ShopSystem::getInstance()->saveAllData();

    return exitCode;
}
