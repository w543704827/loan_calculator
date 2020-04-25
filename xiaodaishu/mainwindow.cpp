#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->calculator,SIGNAL(clicked(bool)),this,SLOT(on_calculator_clicked()));
    connect(this->ui->pecalculator,SIGNAL(clicked(bool)),this,SLOT(on_pecalculator_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reshow(){
    this->show();
}

void MainWindow::on_calculator_clicked()
{
        this->hide();//主界面关闭
        calculator * d = new calculator;//新建子界面
        connect(d,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        d->show();//子界面出

}

void MainWindow::on_pecalculator_clicked()
{
    //this->hide();//主界面关闭
    PEcalculator * d = new PEcalculator;//新建子界面
    //connect(d,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    d->show();//子界面出
}
