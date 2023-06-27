#include "signuppage.h"
#include "ui_signuppage.h"
#include "firstwindow.h"
#include "pwdcmperror.h"
#include <QValidator>
#include "user.h"
#include "signsuccess.h"

extern vector<User>vecuser;
extern User CEO;
extern struct currentUser crtUser;

signUpPage::signUpPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUpPage)
{
    ui->setupUi(this);
    //设置非法输入
    //姓名
    QRegExp regx1("^[\u4e00-\u9fa5]{0,}$");
    QValidator *validator1 = new QRegExpValidator(regx1,ui->lineEdit);
    ui->lineEdit->setValidator(validator1);
    //学号
    QRegExp regx2("[0-9]{0,10}");
    QValidator *validator2 = new QRegExpValidator(regx2,ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator2);
    //手机号
    QRegExp regx3("[0-9]{0,11}");
    QValidator *validator3 = new QRegExpValidator(regx3,ui->lineEdit_3);
    ui->lineEdit_3->setValidator(validator3);
    //密码
    QRegExp regx4("^[A-Za-z0-9]{6,16}$");
    QValidator *validator4 = new QRegExpValidator(regx4,ui->lineEdit_4);
    ui->lineEdit_4->setValidator(validator4);
    ui->lineEdit_5->setValidator(validator4);
}

signUpPage::~signUpPage()
{
    delete ui;
}
//返回按钮
void signUpPage::on_pushButton_2_clicked()
{
    FirstWindow *f = new FirstWindow;
    f->show();
    this->close();
}
//注册按钮
void signUpPage::on_pushButton_clicked()
{
    //获取信息
    QString temp = ui->lineEdit->text();
    std::string name = temp.toStdString();//姓名
    temp = ui->lineEdit_2->text();
    std::string studentID = temp.toStdString();//学号
    temp = ui->lineEdit_3->text();
    std::string phone = temp.toStdString();//手机号
    temp = ui->lineEdit_4->text();
    std::string tempPwd = temp.toStdString();
    temp = ui->lineEdit_5->text();
    std::string tempPwd2 = temp.toStdString();
    std::string password;
    //比较两次密码是否一致
    if(tempPwd == tempPwd2){
        password = tempPwd;//密码
        if(CEO.Registers(phone,password,studentID,name)){
            signSuccess *s = new signSuccess;
            s->show();
        }
    }else{
        pwdCmpError *p = new pwdCmpError;
        p->show();
    }

}
//显示密码
void signUpPage::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()){
        ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_5->setEchoMode(QLineEdit::Normal);
    }else{
        ui->lineEdit_4->setEchoMode(QLineEdit::Password);
        ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    }
}
//回车触发注册按钮
void signUpPage::on_lineEdit_5_returnPressed()
{
    on_pushButton_clicked();
}
