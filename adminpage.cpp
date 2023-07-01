#include "adminpage.h"
#include "ui_adminpage.h"
#include "bookeditpage.h"
#include "statisticspage.h"

adminPage::adminPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);
}

adminPage::~adminPage()
{
    delete ui;
}
//书籍管理
void adminPage::on_pushButton_clicked()
{
    bookEditPage *b = new bookEditPage;
    b->show();
    this->close();
}
//用户管理
void adminPage::on_pushButton_2_clicked()
{

}
//统计页面
void adminPage::on_pushButton_3_clicked()
{
    auto s = new statisticsPage;
    s->show();
    this->close();
}
