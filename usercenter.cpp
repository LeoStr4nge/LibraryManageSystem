#include "usercenter.h"
#include "ui_usercenter.h"
#include "userpage.h"
#include <QValidator>

userCenter::userCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userCenter)
{
    ui->setupUi(this);
    //设置非法输入
    //账号
    QRegExp regx("[a-zA-Z0-9\-\\\_]{10}");
    QValidator *validator = new QRegExpValidator(regx,ui->lineEdit_2);
    ui->lineEdit->setValidator(validator);
    //密码
    QRegExp regx2("[a-zA-Z0-9\-\\\_]{16}");
    QValidator *validator2 = new QRegExpValidator(regx2,ui->lineEdit_3);
    ui->lineEdit_3->setValidator(validator2);
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
