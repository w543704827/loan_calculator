#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();//开始计算


    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

signals:
    void sendLoanYear(QString );
    void sendLoanNum(QString );
    void sendMonthNum(QString);//设置linetext信号
};
#endif // WIDGET_H
