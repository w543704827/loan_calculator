#include "widget.h"
#include "ui_widget.h"
#include <QObject>
#include <QTextBrowser>
#include <QMessageBox>
#include <math.h>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    int loan_num = 0;
    int loan_year = 0;
    float loan_rate = 0;
    double month_num = 0;
    double pay_back_num = 0;

    loan_num = atoi(ui -> lineEdit -> text().toStdString().c_str());
    loan_year = atoi(ui -> lineEdit_2 -> text().toStdString().c_str()) * 12;
    loan_rate = (ui -> lineEdit_3 -> text().toFloat()) / 1200;

    if(loan_num == 0 || loan_rate ==0){
       QMessageBox::information(this , QString("错误"), QString("输入为空！"),QMessageBox::Ok,QMessageBox::NoButton);
    }
    if(loan_year == 0 && loan_num == 0){
        QMessageBox::information(this ,QString("错误"), QString("输入为空！"),QMessageBox::Ok,QMessageBox::NoButton);
    }
    //输入检查

    int loan_model = 0;
    loan_model = ui -> comboBox -> currentIndex();

    if(loan_year == 0){
        loan_model += 2;//如果要计算还款时间，选择后两个计算模式模式
    }

    switch(loan_model){
    case 0:{//计算等额本金还款的每月还款金额
        for(int i = 0; i < loan_year; i++){
            month_num = (loan_num / loan_year) + (loan_num - pay_back_num)*loan_rate;//计算当月还款
            pay_back_num += loan_num / loan_year;

            int rowCount = ui -> tableWidget ->rowCount();
            ui->tableWidget->insertRow(rowCount);//添加行

            QTableWidgetItem *item1 = new QTableWidgetItem;
            QTableWidgetItem *item2 = new QTableWidgetItem;
            QTableWidgetItem *item3 = new QTableWidgetItem;

            item1 -> setText(QString::number(i+1));
            item2 -> setText(QString::number(month_num));
            item3 -> setText(QString::number((loan_num - pay_back_num)<0?0:(loan_num - pay_back_num)));//设置item内容

            ui -> tableWidget -> setItem(rowCount, 0, item1);
            ui -> tableWidget -> setItem(rowCount, 1, item2);
            ui -> tableWidget -> setItem(rowCount, 2, item3);//将item设置到表格
            }break;
        }

    case 1:{
        month_num = loan_num * loan_rate * (pow((1 + loan_rate) , loan_year) / (pow((1 + loan_rate),loan_year) -1));//等额本息计算公式
        for(int i = 0; i < loan_year; i++){
            pay_back_num += month_num - (loan_num - pay_back_num) * loan_rate;

            int rowCount = ui -> tableWidget ->rowCount();
            ui->tableWidget->insertRow(rowCount);//添加行

            QTableWidgetItem *item1 = new QTableWidgetItem;
            QTableWidgetItem *item2 = new QTableWidgetItem;
            QTableWidgetItem *item3 = new QTableWidgetItem;

            item1 -> setText(QString::number(i+1));
            item2 -> setText(QString::number(month_num));
            item3 -> setText(QString::number((loan_num - pay_back_num)<0?0:(loan_num - pay_back_num)));//设置item内容

            ui -> tableWidget -> setItem(rowCount, 0, item1);
            ui -> tableWidget -> setItem(rowCount, 1, item2);
            ui -> tableWidget -> setItem(rowCount, 2, item3);//将item设置到表格
            }
        break;
    }

    case 2:{
        QMessageBox::information(this, QString("错误"), QString("输入为空！请重新输入"), QMessageBox::Ok, QMessageBox::NoButton);
        break;
    }

    case 3:{
        QMessageBox::information(this, QString("错误"), QString("输入为空！请重新输入"), QMessageBox::Ok, QMessageBox::NoButton);
        break;
    }
    }

}

