#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "userpage.h"
#include "ui_userpage.h"
#include "adminpage.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::on_pushButton_clicked()
{
    QString account = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if(account == "admin" && password == "000000") {
        adminPage *a = new adminPage;
        a->show();
        this->close();
    }else{
        this->close();
        userPage *u = new userPage;
        u->show();
    }
    //需要一个检查账号代码是否匹配的函数，返回值1或0
}

void FirstWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_clicked();
}
