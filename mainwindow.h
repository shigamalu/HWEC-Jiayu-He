#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Spinor.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
namespace Ui{
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void easy_game();
    void normal_game();
    void hard_game();
    void exit(){//click the button to exit the game
        close();
        S->get_win()->close();
        S->get_lose()->close();
        ingameexit->close();
        S->close();//we close everything.
    }

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();//click these buttons to select difficulty when entering the game.

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Spinor *S;
    QPushButton* ingameexit;
};

#endif // MAINWINDOW_H
