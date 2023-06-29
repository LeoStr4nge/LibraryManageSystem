#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "userpage.h"
#include "ui_userpage.h"
#include "adminpage.h"
#include "user.h"
#include <QValidator>
#include "signuppage.h"
#include "errors.h"
#include "dialog.h"

extern vector<User>vecuser;
extern User CEO;
extern QString DIALOGMSG;

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    //设置非法输入
    //账号
    QRegExp regx("[a-zA-Z0-9\-\\\_]{11}");
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
    string account = ui->lineEdit->text().toStdString();
    string password = ui->lineEdit_2->text().toStdString();
    //检查用户输入的账号
    //管理员账号
    if(account == "admin" && password == "000000") {
        auto a = new adminPage;
        a->show();
        this->close();
    }else{
        try {
            int flag = CEO.Login(account,password);
            if(flag == 1){
                this->close();
                userPage *u = new userPage;
                u->show();
            }
            else if(flag == 0){
                DIALOGMSG = "密码错误";
                auto d = new Dialog;
                d->show();
            }
            else if(flag == -1){
                DIALOGMSG = "该电话号码未注册";
                auto d = new Dialog;
                d->show();
            }
        } catch (fileError &e) {
            DIALOGMSG = e.what();
            auto d = new Dialog;
            d->show();
        }
    }
}
//由于限制输入，回车不能用于触发登录

//注册按钮
void FirstWindow::on_pushButton_2_clicked()
{
    auto s = new signUpPage;
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
