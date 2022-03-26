#include "mainwindow.h"
#include <QApplication>

#include <QScreen>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* main_page=new MainWindow;
    main_page->setWindowFlags(Qt::Window|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);
    main_page->db_check();
    QScreen* screen=QApplication::primaryScreen();

    int w=screen->geometry().width();
    int h=screen->geometry().height();
    main_page->setGeometry(w/2-(630/2),h/2-(446/2),630,446);







    main_page->login();
    return a.exec();
}
