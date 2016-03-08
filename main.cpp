#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*setQuitOnLastWindowClosed函数设置最后一个主窗口关闭后是否退出程序，默认为true(退出)*/
    QApplication::setQuitOnLastWindowClosed(false);
    MainWindow w;
    w.show();

    return a.exec();
}
