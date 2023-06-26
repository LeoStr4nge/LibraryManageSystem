#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "userpage.h"
#include "ui_userpage.h"
#include "adminpage.h"
#include "user.h"
#include "pwderror.h"
#include "acterror.h"
#include <QValidator>
#include "signuppage.h"
#include "signuppage.h"

extern vector<User>vecuser;
extern User CEO;
FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    //设置非法输入
    //账号
    QRegExp regx("[a-zA-Z0-9\-\\\_]{10}");
    QValidator *validator = new QRegExpValidator(regx,ui->lineEdit);
    ui->lineEdit->setValidator(validator);
    //密码
    QRegExp regx2("[a-zA-Z0-9\-\\\_]{16}");
    QValidator *validator2 = new QRegExpValidator(regx2,ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator2);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

//登录按钮
void FirstWindow::on_pushButton_clicked()
{
    QString temp =  ui->lineEdit->text();
    string account = temp.toStdString();
    temp = ui->lineEdit_2->text();
    string password = temp.toStdString();
    //检查用户输入的账号
    int flag = CEO.Login(account,password);
    //管理员账号
    if(account == "admin" && password == "000000") {
        adminPage *a = new adminPage;
        a->show();
        this->close();
    }else{
        if(flag == 1){
            this->close();
            userPage *u = new userPage;
            u->show();
        }
        else if(flag == 0){
            pwdError *p = new pwdError;
            p->show();
        }
        else if(flag == -1){
            actError *a = new actError;
            a->show();
        }
    }


}
//回车触发登录按钮
void FirstWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_clicked();
}
//注册按钮
void FirstWindow::on_pushButton_2_clicked()
{
    signUpPage *s = new signUpPage;
    s->show();
    this->close();
}
//显示密码
void FirstWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()){
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}
