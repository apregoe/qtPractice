#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("Re:all");
    a.setOrganizationDomain("Re:all.Infogram");
    a.setApplicationName("Re:all - Infogram Software");
    MainWindow* w = new MainWindow;
    w->setAttribute(Qt::WA_QuitOnClose);
    w->show();
    
    return a.exec();
}
