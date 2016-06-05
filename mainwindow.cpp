#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Spinor.h"
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ingameexit = new QPushButton("click me to exit");
    QObject::connect(ingameexit,SIGNAL(clicked()),this,SLOT(exit()));
}

void MainWindow::easy_game() {
    S = new Spinor;
    S->showMaximized();
    S->set_speed(0.5);
    S->go();
    this->hide();//hide mainwindow at start of game.
    if (S->lost())
        ingameexit->show();
    if (S->won())
        ingameexit->show();
}

void MainWindow::normal_game() {
    S = new Spinor;
    S->set_speed(0.75);
    S->showMaximized();
    S->go();
    this->hide();
    if (S->lost())
        ingameexit->show();
    if (S->won())
        ingameexit->show();
}

void MainWindow::hard_game() {
    S = new Spinor;
    S->set_speed(1.0);
    S->showMaximized();
    S->go();
    this->hide();
    if (S->lost())
        ingameexit->show();
    if (S->won())
        ingameexit->show();
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->easy_game();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->normal_game();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->hard_game();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->exit();
}
