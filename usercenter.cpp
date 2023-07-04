#include "usercenter.h"
#include "ui_usercenter.h"
#include "userpage.h"
#include <QValidator>
#include "user.h"
#include "firstwindow.h"
#include "dialog.h"
#include "unreturnbookspage.h"
extern User CEO;
extern QString DIALOGMSG;

userCenter::userCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userCenter)
{
    ui->setupUi(this);
    //设置非法输入
    //姓名
    QRegularExpression regx1("^[\u4e00-\u9fa5]{0,}$");
    QValidator *validator1 = new QRegularExpressionValidator(regx1,ui->lineEdit);
    ui->lineEdit->setValidator(validator1);
    //学号
    QRegularExpression regx2("[0-9]{0,10}");
    QValidator *validator2 = new QRegularExpressionValidator(regx2,ui->lineEdit_5);
    ui->lineEdit_5->setValidator(validator2);
    //密码
    QRegularExpression regx3("^[A-Za-z0-9]{6,16}$");
    QValidator *validator4 = new QRegularExpressionValidator(regx3,ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator4);
    ui->lineEdit_3->setValidator(validator4);
    //获取CEO中的信息并加载到页面中
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
    auto u = new userPage;
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
        if(temp.isEmpty()){
            password = CEO.stdPassword();//原密码
        }else{
            password = tempPwd;//新密码
        }
        CEO.edit(name, phone, studentID, password);
       DIALOGMSG = "编辑成功";
       auto d = new Dialog ;
       d->show();
    }

}
//注销
void userCenter::on_pushButton_3_clicked()
{
    CEO.logout();
    auto f = new FirstWindow;
    f->show();
    this->close();
}
//待还书籍
void userCenter::on_pushButton_4_clicked()
{
    auto u = new unreturnBooksPage;
    u->show();
    this->close();
}
