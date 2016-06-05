/*************Game name: Duet*********
 ******************By:Jiayu He*
 *****************Date:6/3/2016*
 ****************Instructions are in the game.********
 **************** Have fun(I hope)!*/
#include "Spinor.cpp"
#include "mainwindow.cpp"
#include <QApplication>
#include <QObject>
int main(int argc, char *argv[])
{
QApplication a(argc,argv);
MainWindow *m = new MainWindow;
m->show();
return a.exec();
}
