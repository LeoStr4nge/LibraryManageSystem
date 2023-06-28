#include "usercenter.h"
#include "ui_usercenter.h"
#include "userpage.h"
#include <QValidator>
#include "user.h"
#include "firstwindow.h"
#include "editsuccess.h"
extern User CEO;

userCenter::userCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userCenter)
{
    ui->setupUi(this);
    //设置非法输入
    //姓名
    QRegExp regx1("^[\u4e00-\u9fa5]{0,}$");
    QValidator *validator1 = new QRegExpValidator(regx1,ui->lineEdit);
    ui->lineEdit->setValidator(validator1);
    //学号
    QRegExp regx2("[0-9]{0,10}");
    QValidator *validator2 = new QRegExpValidator(regx2,ui->lineEdit_5);
    ui->lineEdit_5->setValidator(validator2);
    //密码
    QRegExp regx3("^[A-Za-z0-9]{6,16}$");
    QValidator *validator4 = new QRegExpValidator(regx3,ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator4);
    ui->lineEdit_3->setValidator(validator4);
    //获取CEO中的信息

    QString crtName = CEO.qName();
    QString crtPhone = CEO.qPhone();
    QString crtID = CEO.qStudentID();
    ui->lineEdit->setText(crtName);
    ui->lineEdit_4->setText(crtPhone);
    ui->lineEdit_5->setText(crtID);
}

userCenter::~userCenter()
{
    delete ui;
}

void userCenter::on_pushButton_clicked()
{
    userPage *u = new userPage;
    u->show();
    this->close();

}
//显示密码
void userCenter::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->checkState()){
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    }else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }
}

void userCenter::on_pushButton_2_clicked()
{
    QString temp = ui->lineEdit->text();
    std::string name = temp.toStdString();//姓名
    temp = ui->lineEdit_4->text();
    std::string phone = temp.toStdString();//手机号
    temp = ui->lineEdit_5->text();
    std::string studentID = temp.toStdString();//学号
    temp = ui->lineEdit_2->text();
    std::string tempPwd = temp.toStdString();//临时密码1
    temp = ui->lineEdit_3->text();
    std::string tempPwd2 = temp.toStdString();//临时密码2
    std::string password;
    //比较两次密码是否一致
    if(tempPwd == tempPwd2){
        if(temp == NULL){
            password = CEO.stdPassword();//原密码
        }else{
            password = tempPwd;//新密码
        }
        CEO.edit(name, phone, studentID, password);
        editSuccess * e = new editSuccess;
        e->show();
    }

}

void userCenter::on_pushButton_3_clicked()
{
    CEO.zhuxiao();
    FirstWindow *f = new FirstWindow;
    f->show();
    this->close();
}
