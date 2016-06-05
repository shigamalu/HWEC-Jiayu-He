#ifndef SPINOR_H
#define SPINOR_H
#include <QtMath>
#include <QMainWindow>
#include <cmath>
#include <QPainter>
#include <QKeyEvent>
#include <QPushButton>
#include <QInputDialog>
const double r = 20.0;
namespace Ui {
class Spinor;
}
class Spinor : public QWidget
{
    Q_OBJECT
public slots:
    void reset(){
        angle = 0.0;//reset positions and widths for a new game.
        slab1_y = 600.0;
        slab2_y = 100.0;
        slab1_width = 300.0;
        slab2_width = 300.0;
        win->hide();
        lose->hide();
        this->showMaximized();
        int option;
        option = QInputDialog::getInt(this, tr("Select an integer"),tr("Difficulty:"), 2, 1, 3, 1);//input integer to choose speed(i.e. difficulty)
        this->set_speed(0.25*option+0.25);
        this->go();
        return;

    }
public:
    explicit Spinor(QWidget *parent = 0);
    ~Spinor();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *e);
    void set_angle(double value);
    QPushButton* get_win() const {return win;}
    QPushButton* get_lose() const {return lose;}
    void slab1sety(double value){slab1_y = value; }//mutators of y positions and widths
    void slab2sety(double value){slab2_y = value; }
    void slab1setwidth(double value){slab1_width = value;}
    void slab2setwidth(double value){slab2_width = value;}
    double slab1getwidth() const{return slab1_width;}//accessors of y positions and widths.
    double slab2getwidth() const{return slab2_width;}
    double slab1gety() const {return slab1_y;}
    double slab2gety() const {return slab2_y;}
    void set_speed(double value){speed = value;}
    void go();//time evolution of the game
    bool slab1_touch() const;//losing condition declarations.
    bool slab2_touch() const;
    void wewon(){win->showMaximized(); this->hide();}
    void welost(){lose->showMaximized(); }//won't hide the game when lost so you can see where you lost.
    QPushButton* getwin() const{return win;}
    QPushButton* getlose() const{return lose;}
    bool lost() const{
        if (slab1_touch() || slab2_touch())
            return true;
        else
            return false;
    }
    bool won() const{return !lost();}
private:
    double angle;
    double x = 1000.0;
    double y = 750.0;
    QPushButton* win;
    QPushButton* lose;
    double slab1_y;
    double slab2_y;
    double slab1_width;
    double slab2_width;
    double speed = 5.0;
};


#endif;
