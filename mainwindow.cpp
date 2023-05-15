#include "mainwindow.h"
#include <bits/stdc++.h>
#include "./ui_mainwindow.h"
#include<QLabel>
#include <QPoint>
#include <QCursor>
using namespace std;
int i = 0;
int chance = 0;
QImage image(1000, 1000, QImage::Format_RGB888);
QRgb value = qRgb(255,0,0);
QRgb value_2 = qRgb(0,255,0);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
class draw{
public:
    int a[4];
};
draw d;

void draw_circle(int xc, int yc, int rad, QRgb value){
    int x=0, y=rad;
    int d = 3 - 2*rad;


    while(x<=y){
        image.setPixel(xc + x, yc + y, value);
        image.setPixel(xc - x, yc + y, value);
        image.setPixel(xc + x, yc - y, value);
        image.setPixel(xc - x, yc - y, value);
        image.setPixel(xc + y, yc + x, value);
        image.setPixel(xc - y, yc + x, value);
        image.setPixel(xc + y, yc - x, value);
        image.setPixel(xc - y, yc - x, value);

        if(d<0)
            d += 4*x+6;
        else{
            d += 4*(x-y)+10;
            y --;
        }
        x ++;

    }
}
void draw_line(int x1, int y1, int x2, int y2, QRgb value){

    float x_inc, y_inc, dx, dy, x, y;
    dx = x2-x1;
    dy = y2-y1;
    int len = abs(dx)>abs(dy)? abs(dx):abs(dy);
    x_inc = dx / len;
    y_inc = dy / len;
    x = x1;
    y = y1;
    for(int i=0; i<len; i++){
        image.setPixel(x, y, value);
        x += x_inc;
        y += y_inc;
    }
}
void draw_linea(int a[],QRgb value){
    float x_inc, y_inc, dx, dy, x, y;
    dx = a[2]- a[0];
    dy = a[3]- a[1];
    int len = abs(dx)>abs(dy)? abs(dx):abs(dy);
    x_inc = dx / len;
    y_inc = dy / len;
    x = a[0];
    y = a[1];
    for(int i=0; i<len; i++){
        image.setPixel(x, y, value);
        x += x_inc;
        y += y_inc;
    }
}
void game(int x,int y){
    if(chance == 0){
        if(i==0){
        d.a[0] = x;
        d.a[1] = y;
        i++;}

        else if(i==1){
            d.a[i+1] = x;
            d.a[i+2] = y;
            i++;
            draw_linea(d.a,value);
            chance++;
            cout<<chance<<endl;
        }
        else{
            for(int q = 0;q<4;q++){
                d.a[q] = 0;
            }
            d.a[0] = x;
            d.a[1] = y;
            i = 1;
        }



        }
        else {
            if(i==0){
            d.a[0] =x;
            d.a[1] = y;
            i++;}

            else if(i==1){
                d.a[i+1] = x;
                d.a[i+2] = y;
                i++;
                draw_linea(d.a,value_2);
                chance = 0;
                cout<<chance<<endl;
            }
            else{
                for(int q = 0;q<4;q++){
                    d.a[q] = 0;
                }
                d.a[0] = x;
                d.a[1] = y;
                i = 1;
            }




        }
}
void MainWindow::on_pushButton_clicked()
{

    value=qRgb(0,255,0);
    draw_circle(50,50,50,value);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();

}


void MainWindow::on_pushButton_2_clicked()
{

//    value=qRgb(0,255,255);
//    draw_line(110,165,210,165,value);
//    draw_line(110,265,210,265,value);

    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();

}


void MainWindow::on_radioButton_pressed()
{   game(110,165);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


void MainWindow::on_radioButton_2_pressed()
{
    game(210,165);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


void MainWindow::on_radioButton_3_pressed()
{
    game(210,265);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
void MainWindow::on_radioButton_4_pressed()
{
    game(110,265);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}



void MainWindow::on_radioButton_5_pressed()
{
    game(310,165);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


void MainWindow::on_radioButton_7_pressed()
{
    game(410,165);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


void MainWindow::on_radioButton_8_pressed()
{
    game(310,265);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


void MainWindow::on_radioButton_6_pressed()
{
    game(410,265);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

