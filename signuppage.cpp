#include "signuppage.h"
#include "ui_signuppage.h"
#include "firstwindow.h"
#include <QValidator>
#include "user.h"
#include "dialog.h"

extern vector<User>vecuser;
extern User CEO;
extern struct currentUser crtUser;
extern QString DIALOGMSG;

signUpPage::signUpPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUpPage)
{
    ui->setupUi(this);
    //设置非法输入
    //姓名
    QRegularExpression regx1("^[\u4e00-\u9fa5]{0,}$");
    QValidator *validator1 = new QRegularExpressionValidator(regx1,ui->lineEdit);
    ui->lineEdit->setValidator(validator1);
    //学号
    QRegularExpression regx2("[0-9]{0,10}");
    QValidator *validator2 = new QRegularExpressionValidator(regx2,ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator2);
    //手机号
    QRegularExpression regx3("[0-9]{0,11}");
    QValidator *validator3 = new QRegularExpressionValidator(regx3,ui->lineEdit_3);
    ui->lineEdit_3->setValidator(validator3);
    //密码
    QRegularExpression regx4("^[A-Za-z0-9]{6,16}$");
    QValidator *validator4 = new QRegularExpressionValidator(regx4,ui->lineEdit_4);
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
    std::string name = ui->lineEdit->text().toStdString();//姓名
    std::string studentID = ui->lineEdit_2->text().toStdString();//学号
    std::string phone = ui->lineEdit_3->text().toStdString();//手机号
    std::string tempPwd = ui->lineEdit_4->text().toStdString();//密码1
    std::string tempPwd2 = ui->lineEdit_5->text().toStdString();//确认密码
    //检查有无空白输入
    if(name.empty()||studentID.empty()||phone.empty()||tempPwd.empty()||tempPwd2.empty()){
        DIALOGMSG = "请完整填写";
        auto d = new Dialog;
        d->show();
    }else{
        std::string password;
        //比较两次密码是否一致
        if(tempPwd == tempPwd2){
            password = tempPwd;//密码
            int flag = CEO.Registers(phone,password,studentID,name);
            if(flag == 1){
                DIALOGMSG = "注册成功";
                auto d = new Dialog;
                d->show();
            }
            else if(flag == 0){
                DIALOGMSG = "该手机号已注册";
                auto d = new Dialog;
                d->show();
            }
        }else{
            DIALOGMSG = "两次密码不一致";
            auto d = new Dialog;
            d->show();
        }
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
