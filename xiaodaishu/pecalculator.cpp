#include "pecalculator.h"
#include "ui_pecalculator.h"

#include <QMessageBox>

PEcalculator::PEcalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PEcalculator)
{
    ui->setupUi(this);

   //connect(ui -> pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
}

PEcalculator::~PEcalculator()
{
    delete ui;
}

void PEcalculator::on_pushButton_bmi_clicked()//正向计算bmi
{
    bool flag = true;
    QString  str1=ui->height->text();
    double height = str1.toDouble();
    QString  str2=ui->weight->text();
    double weight = str2.toDouble();
    if(height == 0 || weight == 0){
        QMessageBox::information(this, QString("错误"), QString("输入为空，请重新输入！"), QMessageBox::Ok);
        flag = false;
    }
    if(height >= 100){
        QMessageBox::information(this, QString("错误"), QString("身高单位为米"), QMessageBox::Ok);
        flag = false;
    }
    if(flag){
        num_bmi = weight/height/height;
        QString a= QString::number(num_bmi);
        ui->bmi->setText(a);
    }
}

void PEcalculator::on_pushButton_3_clicked()//检查身高输入
{
    QString bmi_entered = ui -> bmi ->text();
    double bmi_cal = bmi_entered.toDouble();
    QString h_entered = ui -> height -> text();
    double h_cal = h_entered.toDouble();
    if(bmi_cal == 0 || h_cal == 0){
        QMessageBox::information(this, QString("错误"), QString("输入为空，请重新输入"), QMessageBox::Ok);
    }//输入检查,BMI和身高不能为0
    if(h_cal >= 100){
        QMessageBox::information(this, QString("错误"), QString("身高单位为米"), QMessageBox::Ok);
    }//输入检查，身高单位为米
}

void PEcalculator::on_pushButton_4_clicked()//体重控制反向计算
{
    bool flag = true;
    QString bmi_entered = ui -> bmi -> text();
    double bmi_c = bmi_entered.toDouble();
    QString h_entered = ui -> height ->text();
    double h_c = h_entered.toDouble();//获取输入值，并转为double类型
    if(h_c == 0){
        QMessageBox::information(this, QString("错误"), QString("请输入身高"), QMessageBox::Ok);
        flag = false;
    }
    if(h_c >= 100){
        QMessageBox::information(this, QString("错误"), QString("身高单位为米"), QMessageBox::Ok);
        flag = false;
    }//输入检查，身高单位为米
    if(flag){
        double w = bmi_c * h_c * h_c;//计算标准

        QString w_show = QString::number(w, 'f', 1);//double类型转化为QString，并保留1位小数

        ui -> weight -> setText(w_show);
    }

}

void PEcalculator::cal_score(){
    QString fhl = ui -> fei_hl -> text();
    int s = fhl.toInt();//获取肺活量对应输入值
    QString half_hundred = ui -> halfhundred -> text();
    double h_h = half_hundred.toDouble();//50米
    QString ytxs = ui -> yin_txs -> text();
    int yin_t = ytxs.toInt();//引体向上
    QString longjump = ui -> longjump -> text();
    int l_j = longjump.toInt();//跳远
    QString ywqz = ui -> min_ywqz -> text();
    int yw = ywqz.toInt();//仰卧起坐
    QString b = ui -> bmi -> text();
    double bm = b.toDouble();//bmi
    QString onek = ui -> nailipao -> text();
    double o_k = onek.toDouble();//1000,800米
    QString zwtqq = ui -> zuo_wtqq ->text();
    double zw = zwtqq.toDouble();//坐位体前屈
    QString sc = ui -> score ->text();
    double score_all = sc.toInt();//总分

    int sex_num = ui -> sex -> currentIndex();
    int grand_num = ui -> grand -> currentIndex();

    int item_cal = 100, blank_n = 0;
    if(score_all == 0){
        item_cal = 8;
        blank_n ++;
    }//总分，case8
    if(s == 0){
        item_cal = 0;
        blank_n ++;
    }//肺活量,case0
    if(h_h == 0){
        item_cal = 1;
        blank_n ++;
    }//50米,case1
    if(yin_t == 0){
        item_cal = 2;
        blank_n ++;
    }//引体向上,case2
    if(l_j == 0){
        item_cal = 3;
        blank_n ++;
    }//跳远,case3
    if(yw== 0){
        item_cal = 4;
        blank_n++;
    }//仰卧起坐,case4
    if(bm == 0){
        item_cal = 5;
        blank_n++;
    }//bmi,case5
    if(o_k == 0){
        item_cal = 6;
        blank_n++;
    }//1000，800米,case6
    if(zw == 0){
        item_cal = 7;
        blank_n++;
    }//坐位体前屈,case7


    bool correct = true;
    if(blank_n > 1){
        QMessageBox::information(this, QString("错误"), QString("缺少条件，请重新输入"), QMessageBox::Ok);
        correct = false;
    }//缺省过多则报错

    //计算各科得分
    if(correct){
        int cal_mod = sex_num * 2 + grand_num;
        int fhl_score = 0;//肺活量
        int h = 0;//50m score
        int z = 0;//坐位体前屈score
        int l = 0;//立定跳远score
        int in = 0;//引体向上&仰卧起坐score
        int p = 0;//1km or 0.8km
        int b_sc = 0;//bmi
        switch (cal_mod) {
        case 0:{//男大一大二
                if(s < 2300) fhl_score = 0;
                if(s >= 2300 && s <2460) fhl_score =10;
                if(s >= 2460 && s < 2620) fhl_score = 20;
                if(s >= 2620 && s < 2780) fhl_score = 30;
                if(s >= 2780 && s < 2940) fhl_score = 40;
                if(s >= 2940 && s < 3100) fhl_score = 50;
                if(s >= 3100 && s < 3220) fhl_score = 60;
                if(s >= 3220 && s < 3340) fhl_score = 62;
                if(s >= 3340 && s < 3460) fhl_score = 64;
                if(s >= 3460 && s < 3580) fhl_score = 66;
                if(s >= 3580 && s < 3700) fhl_score = 68;
                if(s >= 3700 && s < 3820) fhl_score = 70;
                if(s >= 3820 && s < 3940) fhl_score = 72;
                if(s >= 3940 && s < 4060) fhl_score = 74;
                if(s >= 4060 && s < 4180) fhl_score = 76;
                if(s >= 4180 && s < 4300) fhl_score = 78;
                if(s >= 4300 && s < 4550) fhl_score = 80;
                if(s >= 4550 && s < 4800) fhl_score = 85;
                if(s >= 4800 && s < 4920) fhl_score = 90;
                if(s >= 4920 && s < 5040) fhl_score = 95;
                if(s > 5040) fhl_score = 100;//计算肺活量成绩

                if(h_h > 10.1) h = 0;
                if(h_h > 9.9 && h_h <= 10.1) h =10;
                if(h_h > 9.7 && h_h <= 9.9) h =20;
                if(h_h > 9.5 && h_h <= 9.7) h =30;
                if(h_h > 9.3 && h_h <= 9.5) h =40;
                if(h_h > 9.1 && h_h <= 9.3) h =50;
                if(h_h > 8.9 && h_h <= 9.1) h =60;
                if(h_h > 8.7 && h_h <= 8.9) h =62;
                if(h_h > 8.5 && h_h <= 8.7) h =64;
                if(h_h > 8.3 && h_h <= 8.5) h =66;
                if(h_h > 8.1 && h_h <= 8.3) h =68;
                if(h_h > 7.9 && h_h <= 8.1) h =70;
                if(h_h > 7.7 && h_h <= 7.9) h =72;
                if(h_h > 7.5 && h_h <= 7.7) h =74;
                if(h_h > 7.3 && h_h <= 7.5) h =76;
                if(h_h > 7.1 && h_h <= 7.3) h =78;
                if(h_h > 7.0 && h_h <= 7.1) h =80;
                if(h_h > 6.9 && h_h <= 7.0) h =85;
                if(h_h > 6.8 && h_h <= 6.9) h =90;
                if(h_h > 6.7 && h_h <= 6.8) h =95;
                if(h_h <= 6.7) h =100;//50米

                if(zw > 24.9) z =100;
                if(zw >= 23.1 && zw < 24.9) z = 95;
                if(zw >= 21.3 && zw < 23.1) z = 90;
                if(zw >= 19.5 && zw < 21.3) z = 85;
                if(zw >= 17.7 && zw < 19.5) z = 80;
                if(zw >= 16.3 && zw < 17.7) z = 78;
                if(zw >= 14.9 && zw < 16.3) z = 76;
                if(zw >= 13.5 && zw < 14.9) z = 74;
                if(zw >= 12.1 && zw < 13.5) z = 72;
                if(zw >= 10.7 && zw < 12.1) z = 70;
                if(zw >= 9.3 && zw < 10.7) z = 68;
                if(zw >= 7.9 && zw < 9.3) z = 66;
                if(zw >= 6.5 && zw < 7.9) z = 64;
                if(zw >= 5.1 && zw < 6.5) z = 62;
                if(zw >= 3.7 && zw < 5.1) z = 60;
                if(zw >= 2.7 && zw < 3.7) z = 50;
                if(zw >= 1.7 && zw < 2.7) z = 40;
                if(zw >= 0.7 && zw < 1.7) z = 30;
                if(zw >= -0.3 && zw < 0.7) z = 20;
                if(zw >= -1.3 && zw < -0.3) z = 10;
                if(zw < -1.3) z = 0;//坐位体前屈

                if(l_j >= 273) l = 100;
                if(l_j >= 268 && l_j < 273) l = 95;
                if(l_j >= 263 && l_j < 268) l = 90;
                if(l_j >= 256 && l_j < 263) l = 85;
                if(l_j >= 248 && l_j < 256) l = 80;
                if(l_j >= 244 && l_j < 248) l = 78;
                if(l_j >= 240 && l_j < 244) l = 76;
                if(l_j >= 236 && l_j < 240) l = 74;
                if(l_j >= 232 && l_j < 236) l = 72;
                if(l_j >= 228 && l_j < 232) l = 70;
                if(l_j >= 224 && l_j < 228) l = 68;
                if(l_j >= 220 && l_j < 224) l = 66;
                if(l_j >= 216 && l_j < 220) l = 64;
                if(l_j >= 212 && l_j < 216) l = 62;
                if(l_j >= 208 && l_j < 212) l = 60;
                if(l_j >= 203 && l_j < 208) l = 50;
                if(l_j >= 198 && l_j < 203) l = 40;
                if(l_j >= 193 && l_j < 198) l = 30;
                if(l_j >= 188 && l_j < 193) l = 20;
                if(l_j >= 183 && l_j < 188) l = 10;
                if(l_j < 183) l = 0;//立定跳远

                if(yin_t >= 19) in = 100;
                if(yin_t == 18) in = 95;
                if(yin_t == 17) in = 90;
                if(yin_t == 16) in = 85;
                if(yin_t == 15) in = 80;
                if(yin_t == 14) in = 76;
                if(yin_t == 13) in = 72;
                if(yin_t == 12) in = 68;
                if(yin_t == 11) in = 64;
                if(yin_t == 10) in = 60;
                if(yin_t == 9) in = 50;
                if(yin_t == 8) in = 40;
                if(yin_t == 7) in = 30;
                if(yin_t == 6) in = 20;
                if(yin_t == 5) in = 10;
                if(yin_t < 5) in = 0;//引体向上

                if(o_k <= 3.17) p = 100;
                if(o_k <= 3.22 && o_k > 3.17) p = 95;
                if(o_k <= 3.27 && o_k > 3.22) p = 90;
                if(o_k <= 3.34 && o_k > 3.27) p = 85;
                if(o_k <= 3.42 && o_k > 3.34) p = 80;
                if(o_k <= 3.47 && o_k > 3.42) p = 78;
                if(o_k <= 3.52 && o_k > 3.47) p = 76;
                if(o_k <= 3.57 && o_k > 3.52) p = 74;
                if(o_k <= 4.02 && o_k > 3.57) p = 72;
                if(o_k <= 4.07 && o_k > 4.02) p = 70;
                if(o_k <= 4.12 && o_k > 4.07) p = 68;
                if(o_k <= 4.17 && o_k > 4.12) p = 66;
                if(o_k <= 4.22 && o_k > 4.17) p = 64;
                if(o_k <= 4.27 && o_k > 4.22) p = 62;
                if(o_k <= 4.32 && o_k > 4.27) p = 60;
                if(o_k <= 4.52 && o_k > 4.32) p = 50;
                if(o_k <= 5.12 && o_k > 4.52) p = 40;
                if(o_k <= 5.32 && o_k > 5.12) p = 30;
                if(o_k <= 5.52 && o_k > 5.32) p = 20;
                if(o_k <= 6.12 && o_k > 5.52) p = 10;
                if(o_k > 6.12) p = 0;//1000m

                if(bm <= 17.8) b_sc = 80;
                if(bm > 24 && bm <= 27.9) b_sc =80;
                if(bm > 17.9 && bm <= 23.9) b_sc = 100;
                if(bm >= 28) b_sc =60;//bmi

                //计算总成绩
               //score_all = b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2;
                break;
            }
        case 1:{//男大三大四
            if(s < 2350) fhl_score = 0;
            if(s >= 2350 && s <2520) fhl_score =10;
            if(s >= 2520 && s < 2690) fhl_score = 20;
            if(s >= 2690 && s < 2860) fhl_score = 30;
            if(s >= 2860 && s < 3030) fhl_score = 40;
            if(s >= 3030 && s < 3200) fhl_score = 50;
            if(s >= 3200 && s < 3320) fhl_score = 60;
            if(s >= 3320 && s < 3440) fhl_score = 62;
            if(s >= 3440 && s < 3560) fhl_score = 64;
            if(s >= 3560 && s < 3680) fhl_score = 66;
            if(s >= 3680 && s < 3800) fhl_score = 68;
            if(s >= 3800 && s < 3920) fhl_score = 70;
            if(s >= 3920 && s < 4040) fhl_score = 72;
            if(s >= 4040 && s < 4160) fhl_score = 74;
            if(s >= 4160 && s < 4280) fhl_score = 76;
            if(s >= 4280 && s < 4400) fhl_score = 78;
            if(s >= 4400 && s < 4650) fhl_score = 80;
            if(s >= 4650 && s < 4900) fhl_score = 85;
            if(s >= 4900 && s < 5020) fhl_score = 90;
            if(s >= 5020 && s < 5140) fhl_score = 95;
            if(s > 5140) fhl_score = 100;//计算肺活量成绩

            if(h_h > 10.0) h = 0;
            if(h_h > 9.8 && h_h <= 10.0) h =10;
            if(h_h > 9.6 && h_h <= 9.8) h =20;
            if(h_h > 9.4 && h_h <= 9.6) h =30;
            if(h_h > 9.2 && h_h <= 9.4) h =40;
            if(h_h > 9.0 && h_h <= 9.2) h =50;
            if(h_h > 8.8 && h_h <= 9.0) h =60;
            if(h_h > 8.6 && h_h <= 8.8) h =62;
            if(h_h > 8.4 && h_h <= 8.6) h =64;
            if(h_h > 8.2 && h_h <= 8.4) h =66;
            if(h_h > 8.0 && h_h <= 8.2) h =68;
            if(h_h > 7.8 && h_h <= 8.0) h =70;
            if(h_h > 7.6 && h_h <= 7.8) h =72;
            if(h_h > 7.4 && h_h <= 7.6) h =74;
            if(h_h > 7.2 && h_h <= 7.4) h =76;
            if(h_h > 7.0 && h_h <= 7.2) h =78;
            if(h_h > 6.9 && h_h <= 7.0) h =80;
            if(h_h > 6.8 && h_h <= 6.9) h =85;
            if(h_h > 6.7 && h_h <= 6.8) h =90;
            if(h_h > 6.6 && h_h <= 6.7) h =95;
            if(h_h <= 6.6) h =100;//50米

            if(zw > 25.1) z =100;
            if(zw >= 23.3 && zw < 25.1) z = 95;
            if(zw >= 21.5 && zw < 23.3) z = 90;
            if(zw >= 19.9 && zw < 21.5) z = 85;
            if(zw >= 18.2 && zw < 19.9) z = 80;
            if(zw >= 16.8 && zw < 18.2) z = 78;
            if(zw >= 15.4 && zw < 16.8) z = 76;
            if(zw >= 14.0 && zw < 15.4) z = 74;
            if(zw >= 12.6 && zw < 14.0) z = 72;
            if(zw >= 11.2 && zw < 12.6) z = 70;
            if(zw >= 9.8 && zw < 11.2) z = 68;
            if(zw >= 8.4 && zw < 9.8) z = 66;
            if(zw >= 7.0 && zw < 8.4) z = 64;
            if(zw >= 5.6 && zw < 7.0) z = 62;
            if(zw >= 4.2 && zw < 5.6) z = 60;
            if(zw >= 3.2 && zw < 4.2) z = 50;
            if(zw >= 2.2 && zw < 3.2) z = 40;
            if(zw >= 1.2 && zw < 2.2) z = 30;
            if(zw >= 0.2 && zw < 1.2) z = 20;
            if(zw >= -0.8 && zw < 0.2) z = 10;
            if(zw < -0.8) z = 0;//坐位体前屈

            if(l_j >= 275) l = 100;
            if(l_j >= 270 && l_j < 275) l = 95;
            if(l_j >= 265 && l_j < 270) l = 90;
            if(l_j >= 258 && l_j < 265) l = 85;
            if(l_j >= 250 && l_j < 258) l = 80;
            if(l_j >= 246 && l_j < 250) l = 78;
            if(l_j >= 242 && l_j < 246) l = 76;
            if(l_j >= 238 && l_j < 242) l = 74;
            if(l_j >= 234 && l_j < 238) l = 72;
            if(l_j >= 230 && l_j < 234) l = 70;
            if(l_j >= 226 && l_j < 230) l = 68;
            if(l_j >= 222 && l_j < 226) l = 66;
            if(l_j >= 218 && l_j < 222) l = 64;
            if(l_j >= 214 && l_j < 218) l = 62;
            if(l_j >= 210 && l_j < 214) l = 60;
            if(l_j >= 205 && l_j < 210) l = 50;
            if(l_j >= 200 && l_j < 205) l = 40;
            if(l_j >= 195 && l_j < 200) l = 30;
            if(l_j >= 190 && l_j < 195) l = 20;
            if(l_j >= 185 && l_j < 190) l = 10;
            if(l_j < 185) l = 0;//立定跳远

            if(yin_t >= 20) in = 100;
            if(yin_t == 19) in = 95;
            if(yin_t == 18) in = 90;
            if(yin_t == 17) in = 85;
            if(yin_t == 16) in = 80;
            if(yin_t == 15) in = 76;
            if(yin_t == 14) in = 72;
            if(yin_t == 13) in = 68;
            if(yin_t == 12) in = 64;
            if(yin_t == 11) in = 60;
            if(yin_t == 10) in = 50;
            if(yin_t == 9) in = 40;
            if(yin_t == 8) in = 30;
            if(yin_t == 7) in = 20;
            if(yin_t == 6) in = 10;
            if(yin_t < 6) in = 0;//引体向上

            if(o_k <= 3.15) p = 100;
            if(o_k <= 3.20 && o_k > 3.15) p = 95;
            if(o_k <= 3.25 && o_k > 3.20) p = 90;
            if(o_k <= 3.32 && o_k > 3.25) p = 85;
            if(o_k <= 3.40 && o_k > 3.32) p = 80;
            if(o_k <= 3.45 && o_k > 3.40) p = 78;
            if(o_k <= 3.50 && o_k > 3.45) p = 76;
            if(o_k <= 3.55 && o_k > 3.50) p = 74;
            if(o_k <= 4.00 && o_k > 3.55) p = 72;
            if(o_k <= 4.05 && o_k > 4.00) p = 70;
            if(o_k <= 4.10 && o_k > 4.05) p = 68;
            if(o_k <= 4.15 && o_k > 4.10) p = 66;
            if(o_k <= 4.20 && o_k > 4.15) p = 64;
            if(o_k <= 4.25 && o_k > 4.20) p = 62;
            if(o_k <= 4.30 && o_k > 4.25) p = 60;
            if(o_k <= 4.50 && o_k > 4.30) p = 50;
            if(o_k <= 5.10 && o_k > 4.50) p = 40;
            if(o_k <= 5.30 && o_k > 5.10) p = 30;
            if(o_k <= 5.50 && o_k > 5.30) p = 20;
            if(o_k <= 6.10 && o_k > 5.50) p = 10;
            if(o_k > 6.10) p = 0;//1000m

            if(bm <= 17.8) b_sc = 80;
            if(bm > 24 && bm <= 27.9) b_sc =80;
            if(bm > 17.9 && bm <= 23.9) b_sc = 100;
            if(bm >= 28) b_sc =60;//bmi

            //计算总成绩
            //score_all = b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2;

            break;
        }
        case 2:{//大一大二女
            if(bm <= 17.1) b_sc = 80;
            if(bm >= 28.0) b_sc = 60;
            if(bm > 17.2 && bm <= 23.9) b_sc = 100;
            if(bm > 24.0 && bm <= 27.9) b_sc = 80;//bmi

            int a[20] = {1800,1840,1880,1920,1960,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3150,3300,3350,3400};
            //肺活量数组
            double b[20] = {11.3,11.1,10.9,10.7,10.5,10.3,10.1,9.9,9.7,9.5,9.3,9.1,8.9,8.7,8.5,8.3,8.0,7.7,7.6,7.5};
            //50m数组
            double c[20] = {2.0,2.8,3.6,4.4,5.2,6.0,7.3,8.6,9.9,11.2,12.5,13.8,15.1,16.4,17.7,19.0,20.6,22.2,24.0,25.8};
            //坐位体前屈
            int d[20] = {126,131,136,141,146,151,154,157,160,163,166,169,172,175,178,181,188,195,201,207};
            //立定跳远
            int e[20] = {16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,49,52,54,56};
            //仰卧起坐
            double f[20] = {5.24,5.14,5.04,4.54,4.44,4.34,4.29,4.24,4.19,4.14,4.09,4.04,3.59,3.54,3.49,3.44,3.37,3.30,3.24,3.18};
            //800米
            int sc[20] = {10,20,30,40,50,60,62,64,66,68,70,72,74,76,78,80,85,90,95,100};


            for(int i = 0; i < 20; i++){
                if(s < a[0]) {fhl_score = 0;break;}
                if(s >= a[19]) {fhl_score = 100;break;}
                if(s >= a[i] && s < a[i+1]) {fhl_score = sc[i];break;}
            }//肺活量成绩


            for(int i = 0; i < 20; i++){
                if(h_h > b[0]) {h = 0;break;}
                if(h_h <= b[19]) {h = 100;break;}
                if(h_h <= b[i] && h_h > b[i+1]) {h = sc[i];break;}
            }//50m

            for(int i = 0; i < 20; i++){
                if(zw < c[0]){
                    z = 0;
                    break;
                }
                if(zw >= c[19]){
                    z = 100;
                    break;
                }
                if(zw >= c[i] && zw < c[i+1]){
                    z = sc[i];
                    break;
                }
            }//坐位体前屈

            for(int i = 0; i < 20; i++){
                if(l_j < d[0]){
                    l = 0;
                    break;
                }
                if(l_j >= d[19]){
                    l = 100;
                    break;
                }
                if(l_j >= d[i] && l_j < d[i+1]){
                    l = sc[i];
                    break;
                }
            }//立定跳远

            for(int i = 0; i < 20; i++){
                if(yw < e[0]){
                    in = 0;
                    break;
                }
                if(yw >= e[19]){
                    in = 100;
                    break;
                }
                if(yw >= e[i] && yw < e[i+1]){
                    in = sc[i];
                    break;
                }
            }//仰卧起坐

            for(int i = 0; i < 20; i++){
                if(o_k > f[0]){
                    p = 0;
                    break;
                }
                if(o_k <= f[19]){
                    p = 100;
                    break;
                }
                if(o_k <= f[i] && o_k > f[i+1]){
                    p = sc[i];
                    break;
                }//800m
            }

            //总成绩
            //score_all = b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2;
            break;
        }
        case 3:{//大三大四女
            if(bm <= 17.1) b_sc = 80;
            if(bm >= 28.0) b_sc = 60;
            if(bm > 17.2 && bm <= 23.9) b_sc = 100;
            if(bm > 24.0 && bm <= 27.9) b_sc = 80;//bmi

            int a[20] = {1800,1840,1880,1920,1960,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3150,3300,3350,3400};
            for (int i = 0; i < 20; i++){
                a[i] += 50;
            }//肺活量数组
            double b[20] = {11.3,11.1,10.9,10.7,10.5,10.3,10.1,9.9,9.7,9.5,9.3,9.1,8.9,8.7,8.5,8.3,8.0,7.7,7.6,7.5};
            for(int i = 0; i < 20; i++) b[i] -= 0.1;
            //50m数组
            double c[20] = {2.0,2.8,3.6,4.4,5.2,6.0,7.3,8.6,9.9,11.2,12.5,13.8,15.1,16.4,17.7,19.0,21,22.4,24.4,26.3};
            for(int i = 0; i < 16; i++){
                c[i] += 0.5;
            }
            //坐位体前屈
            int d[20] = {126,131,136,141,146,151,154,157,160,163,166,169,172,175,178,181,188,195,201,207};
            for(int i = 0;i < 20; i++) d[i] +=1;
            //立定跳远
            int e[20] = {16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,49,52,54,56};
            for(int i = 0;i < 20; i++) e[i] += 1;
            //仰卧起坐
            double f[20] = {5.24,5.14,5.04,4.54,4.44,4.34,4.29,4.24,4.19,4.14,4.09,4.04,3.59,3.54,3.49,3.44,3.37,3.30,3.24,3.18};
            for(int i = 0; i < 20; i++) f[i] -= 0.02;
            //800米
            int sc[20] = {10,20,30,40,50,60,62,64,66,68,70,72,74,76,78,80,85,90,95,100};


            for(int i = 0; i < 20; i++){
                if(s < a[0]) {fhl_score = 0;break;}
                if(s >= a[19]) {fhl_score = 100;break;}
                if(s >= a[i] && s < a[i+1]) {fhl_score = sc[i];break;}
            }//肺活量成绩


            for(int i = 0; i < 20; i++){
                if(h_h > b[0]) {h = 0;break;}
                if(h_h <= b[19]) {h = 100;break;}
                if(h_h <= b[i] && h_h > b[i+1]) {h = sc[i];break;}
            }//50m

            for(int i = 0; i < 20; i++){
                if(zw < c[0]){
                    z = 0;
                    break;
                }
                if(zw >= c[19]){
                    z = 100;
                    break;
                }
                if(zw >= c[i] && zw < c[i+1]){
                    z = sc[i];
                    break;
                }
            }//坐位体前屈

            for(int i = 0; i < 20; i++){
                if(l_j < d[0]){
                    l = 0;
                    break;
                }
                if(l_j >= d[19]){
                    l = 100;
                    break;
                }
                if(l_j >= d[i] && l_j < d[i+1]){
                    l = sc[i];
                    break;
                }
            }//立定跳远

            for(int i = 0; i < 20; i++){
                if(yw < e[0]){
                    in = 0;
                    break;
                }
                if(yw >= e[19]){
                    in = 100;
                    break;
                }
                if(yw >= e[i] && yw < e[i+1]){
                    in = sc[i];
                    break;
                }
            }//仰卧起坐

            for(int i = 0; i < 20; i++){
                if(o_k > f[0]){
                    p = 0;
                    break;
                }
                if(o_k <= f[19]){
                    p = 100;
                    break;
                }
                if(o_k <= f[i] && o_k > f[i+1]){
                    p = sc[i];
                    break;
                }//800m
            }

            //总成绩
            //score_all = b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2;

            break;
        }
        }

        switch (item_cal) {
        case 8:{
            score_all = b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2;
            ui -> score -> setText(QString::number(score_all));
            break;
        }//计算总分
        case 4:{
            in = (score_all -  (b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + p * 0.2))/0.1;
            ui -> min_ywqz -> setText(QString::number(in));
            break;
        }//仰卧起坐&引体向上
        case 7:{
            z = (score_all - ( b_sc * 0.15 + fhl_score * 0.15 + h * 0.2  + l * 0.1 + in * 0.1 + p * 0.2))/0.1;
            ui -> zuo_wtqq -> setText(QString::number(z));
            break;
        }//坐位体前屈
        case 6:{
            p = (score_all - (b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1))/0.2;
            ui -> nailipao -> setText(QString::number(p));
            break;
        }//耐力跑
        case 5:{
            b_sc = (score_all - (fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2))/0.15;
            ui -> bmi -> setText(QString::number(b_sc));
            break;
        }//bmi
        case 3:{
            l = (score_all - ( b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + in * 0.1 + p * 0.2))/0.1;
            ui -> longjump -> setText(QString::number(l));
            break;
        }//跳远
        case 2:{
            in = (score_all -  (b_sc * 0.15 + fhl_score * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + p * 0.2))/0.1;
            ui -> yin_txs -> setText(QString::number(in));
            break;
        }//引体向上
        case 1:{
            h = (score_all - (b_sc * 0.15 + fhl_score * 0.15 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2))/0.2;
            ui -> halfhundred -> setText(QString::number(h));
            break;
        }//50m
        case 0:{
            fhl_score = (score_all - (b_sc * 0.15 + h * 0.2 + z * 0.1 + l * 0.1 + in * 0.1 + p * 0.2))/0.15;
            ui -> bmi -> setText(QString::number(fhl_score));
            break;
        }//肺活量
        }
    }
}

void PEcalculator::on_pushButton_5_clicked()//肺活量计算
{

}
//connect(ui->sex, SIGNAL(currentIndexChanged(const "大一 大二" &)), ui->score, SLOT(void()(const QString &)));

/*void PEcalculator::on_pushButton_score_clicked()
{


}*/

void PEcalculator::on_sure_clicked()//确认键
{
    cal_score();
}


void PEcalculator::on_cancel_clicked()//返回键
{
    this -> close();
}
