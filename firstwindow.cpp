#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "userpage.h"
#include "ui_userpage.h"
#include "adminpage.h"
#include "user.h"

extern vector<User>vecuser;
extern User CEO;
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
    QString temp =  ui->lineEdit->text();
    string account = temp.toStdString();
    temp = ui->lineEdit_2->text();
    string password = temp.toStdString();
    //需要一个检查账号代码是否匹配的函数，返回值1或0

    CEO.Login(account,password);

    if(account == "admin" && password == "000000") {
        adminPage *a = new adminPage;
        a->show();
        this->close();
    }else{
        this->close();
        userPage *u = new userPage;
        u->show();
    }


}

void FirstWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_clicked();
}

void FirstWindow::on_pushButton_2_clicked()
{
    QString temp =  ui->lineEdit->text();
    string account = temp.toStdString();
    temp = ui->lineEdit_2->text();
    string password = temp.toStdString();


    CEO.Registers(account, password);
    CEO.save();
}
