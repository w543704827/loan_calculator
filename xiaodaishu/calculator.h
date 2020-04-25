#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include<QString>
#include<QTimer>
namespace Ui {
class calculator;
}

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();

private slots:

    void on_pushButton_Exit_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_jian_clicked();

    void on_pushButton_chen_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_BackSpace_clicked();

    void on_pushButton_00_clicked();
signals:
    void sendsignal();

private:
    Ui::calculator *ui;
    QString process;
    float result;
    QString S;
    QString Sresult;
    float sum;
    int choose;//根据choose的值来判断究竟选了哪个运算符
    int stat;//根据stat的值来判断是否按了其他运算符
    int dot;
};

#endif
