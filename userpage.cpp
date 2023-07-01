#include "userpage.h"
#include "ui_userpage.h"
#include "searchpage.h"
#include "ui_searchpage.h"
#include "usercenter.h"
#include "firstwindow.h"

userPage::userPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userPage)
{
    ui->setupUi(this);
}

userPage::~userPage()
{
    delete ui;
}

void userPage::on_pushButton_clicked()
{
    searchPage *s = new searchPage;
    s->show();
    this->close();
}

void userPage::on_pushButton_2_clicked()
{
    userCenter *u = new userCenter;
    u->show();
    this->close();
}
//退出登录
void userPage::on_pushButton_3_clicked()
{
    auto f = new FirstWindow;
    f->show();
    this->close();
}
