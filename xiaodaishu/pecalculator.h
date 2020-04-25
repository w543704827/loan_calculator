#ifndef PECALCULATOR_H
#define PECALCULATOR_H

#include <QMainWindow>
#include<QString>
#include<QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>


namespace Ui {
class PEcalculator;
}

class PEcalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit PEcalculator(QWidget *parent = nullptr);
    ~PEcalculator();

    void cal_score();

signals:
    void sendsignal();

private slots:
    void on_pushButton_bmi_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_sure_clicked();

    void on_cancel_clicked();

private:
    Ui::PEcalculator *ui;

    double num_bmi;
    double num_score;
    int choose_sex;//1为男生，2为女生
    int choose_grand;//1为大一大二，2为大三大四



};

#endif // PECALCULATOR_H
