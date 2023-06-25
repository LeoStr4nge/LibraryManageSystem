#include "usercenter.h"
#include "ui_usercenter.h"
#include "usercenter.h"

userCenter::userCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userCenter)
{
    ui->setupUi(this);
}

userCenter::~userCenter()
{
    delete ui;
}

void userCenter::on_pushButton_clicked()
{
    userCenter *u = new userCenter;
    u->show();
    this->close();
}
