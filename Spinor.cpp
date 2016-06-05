#include "Spinor.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QApplication>
#include <QVector>
#include <QtGlobal>
#include <QFont>
#include <QString>
#include <QFont>
#include <QTimer>
#include <ctime>
Spinor::Spinor(QWidget *parent){//constructor
    angle = 0.0;
    QString Won = "Victory! :) \n For further games,click here and choose 1 in the new window for easy,2 for normal, and 3 for hard. \n Otherwise click the exit button."; //winning and losing interfaces are linked to further games.
    QString Lost = "we lost :( \n For further games,click here and choose 1 in the new window for easy,2 for normal, and 3 for hard. \n Otherwise click the exit button.";
    win = new QPushButton(Won);
    lose = new QPushButton(Lost);
    slab1_y = 600.0;
    slab2_y = 100.0;
    slab1_width = 300.0;
    slab2_width = 300.0;
    QFont font1 = this->win->font();
    QFont font2 = this->lose->font();
    font1.setPointSize(18);//enlarge font on the screen.
    font2.setPointSize(18);
    this->win->setFont(font1);
    this->lose->setFont(font2);
    QObject::connect(this->get_lose(), SIGNAL(clicked()),this, SLOT(reset()));
    QObject::connect(this->get_win(), SIGNAL(clicked()),this, SLOT(reset()));
}
Spinor::~Spinor(){//destructor
    angle = 0;
    x = 0;
    y = 0;
    speed = 0;
    delete win;
    delete lose;
}
void Spinor::set_angle(double value){
    angle = value;
    angle = fmod(angle,360);
    return;
}
void Spinor::keyPressEvent(QKeyEvent *e){
    QTimer c;
    c.setInterval(25);
    switch (e->key()) {
    case Qt::Key_Z:
        angle += 8.0;
        angle = fmod(angle,360);
        break;
    case Qt::Key_M:
        angle -= 8.0;
        angle = fmod(angle,360);
        break;
    default:
        QWidget::keyPressEvent(e);
    }

    QCoreApplication::processEvents();
    repaint();
    return;
}
void Spinor::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    double width = 55.5;//the orbs are drawn within a 55.5*55.5 square.
    double height = 55.5;
    painter.setBrush( Qt::red );
    qreal X_coordinate1 = x+200.0*qCos(qDegreesToRadians(angle));
    qreal Y_coordinate1 = y+200.0*qSin(qDegreesToRadians(angle));
    qreal X_coordinate2 = x-200.0*qCos(qDegreesToRadians(angle));
    qreal Y_coordinate2 = y-200.0*qSin(qDegreesToRadians(angle));
    QRectF rectangle1(X_coordinate1, Y_coordinate1, width, height);
    QRectF rectangle2(X_coordinate2, Y_coordinate2, width, height);
    painter.drawEllipse(rectangle1);
    painter.setBrush( Qt::blue );
    painter.drawEllipse(rectangle2);
    painter.setBrush( Qt::black );
    QRectF slab1(1000.0-0.45*slab1_width,slab1gety(),slab1_width,55.5);
    QRectF slab2(1000.0-0.45*slab2_width,slab2gety(),slab2_width,55.5);
    QRectF slab1_left(500,slab1gety(),(1000.0-slab1_width)/2-150.0,55.5);
    QRectF slab1_right(1500.0-(1000.0-slab1_width)/2+135.0,slab1gety(),(1000.0-slab1_width)/2-135.0,55.5);
    QRectF slab2_left(500,slab2gety(),(1000.0-slab2_width)/2-150.0,55.5);
    QRectF slab2_right(1500.0-(1000.0-slab2_width)/2+135.0,slab2gety(),(1000.0-slab2_width)/2-135.0,55.5);
    QRectF shade1(0,0,500,1000);
    QRectF shade2(1500,0,500,1000);
    painter.drawRect(slab1);
    painter.drawRect(slab1_left);
    painter.drawRect(slab1_right);
    painter.drawRect(slab2);
    painter.drawRect(slab2_left);
    painter.drawRect(slab2_right);
    painter.drawRect(shade1);
    painter.drawRect(shade2);
    return;
}
bool Spinor::slab1_touch() const{//losing conditions are basically Pythagorean theorem.
    if (abs(200.0*qCos(qDegreesToRadians(angle))) < (slab1getwidth())/2.0){
        if ((slab1gety()+55.5) >= (750.0-(r+200.0*abs(qSin(qDegreesToRadians(angle))))))
            return true;
        if (((slab1gety()+55.5) >= (750.0+(-r+200.0*abs(qSin(qDegreesToRadians(angle)))))))
            return true;
        if (((slab1gety()) <= (750.0-(-r+200.0*abs(qSin(qDegreesToRadians(angle)))))))
            return true;
        if (((slab1gety()) <= (750.0+(r+200.0*abs(qSin(qDegreesToRadians(angle)))))))
            return true;
        else
            return false;
    }
    else{
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))-r)<=slab1getwidth()/2.0) && ((slab1gety()+55.5>=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r))) ) && ((slab1gety()<=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r)))))
            return true;
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))-r)<=slab1getwidth()/2.0) && ((slab1gety()<=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle)))-r)))) && ((slab1gety()+55.5>=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle)))-r)))))
            return true;
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))+28.0)>=(135.0+slab1getwidth()/2.0)) && ((slab1gety()+55.5>=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r)))  ) && ((slab1gety()<=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r)))))
            return true;
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))+28.0)>=(135.0+slab1getwidth()/2.0)) && ((slab1gety()<=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle))+r))))) && ((slab1gety()+55.5>=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle)))-r)))))
            return true;
        else
            return false;
    }
}
bool Spinor::slab2_touch() const{
    if (abs(200.0*qCos(qDegreesToRadians(angle))) < (slab2getwidth())/2.0){
        if ((slab2gety()+55.5) >= (750.0-(r+200.0*abs(qSin(qDegreesToRadians(angle))))))
            return true;
        if (((slab2gety()+55.5) >= (750.0+(-r+200.0*abs(qSin(qDegreesToRadians(angle)))))))
            return true;
        if (((slab2gety()) <= (750.0-(-r+200.0*abs(qSin(qDegreesToRadians(angle)))))))
            return true;
        if (((slab2gety()) <= (750.0+(r+200.0*abs(qSin(qDegreesToRadians(angle)))))))
            return true;
        else
            return false;
    }
    else{
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))-r)<=slab2getwidth()/2.0) && (slab2gety()+55.5>=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r))) && ((slab2gety()<=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r)))))
            return true;
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))-r)<=slab2getwidth()/2.0) && (slab2gety()<=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle))-r)))) && ((slab2gety()+55.5>=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle)))-r)))))
            return true;
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))+28.0)>=(135.0+slab2getwidth()/2.0)) && (slab2gety()+55.5>=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r))) && ((slab2gety()<=(750.0-(200.0*abs(qSin(qDegreesToRadians(angle)))+r)))))
            return true;
        if (((abs(200.0*qCos(qDegreesToRadians(angle)))+28.0)>=(135.0+slab2getwidth()/2.0)) && (slab2gety()<=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle)))+r))) && ((slab2gety()+55.5>=(750.0+(200.0*abs(qSin(qDegreesToRadians(angle)))-r)))))
            return true;
        else
            return false;
    }
}
void Spinor::go(){//this function is responsible for motion of the slabs.
    qsrand(time(NULL));
    QVector<double> v;
    v.resize(0);
    for (int i=0;i<5;i++){
        v.push_back(300.0-1.0*i*30);
    }//widths range from 150 to 300 and come out randomly.
    int t = 0;
    while (t<6000){
        slab1_y+=speed;
        slab2_y+=speed;
        if (slab1_y>(1000.0-55.5)){
            slab1setwidth(v[qrand() % 5]);

            slab1_y = fmod(slab1_y,(1000.0-55.5));}
        if (slab2_y>(1000-55.5)){
            slab2setwidth(v[qrand() % 5]);

            slab2_y = fmod(slab2_y,(1000.0-55.5));}
        QCoreApplication::processEvents();
        repaint();
        if (slab1_touch() || slab2_touch()){//if losing condition satisfied,game is lost and the losing interface pops up
            this->welost();
            return;}
        t++;
    }
    this->wewon();//if a time passes by and still we have not lost,win.
    return;
}
