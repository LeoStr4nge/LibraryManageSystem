#include "searchpage.h"
#include "ui_searchpage.h"
#include "userpage.h"
#include <string>

searchPage::searchPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
}

searchPage::~searchPage()
{
    delete ui;
}

//返回按钮
void searchPage::on_pushButton_2_clicked()
{
    userPage* n = new userPage;
    n->show();
    this->close();
}
//回车绑定按钮
void searchPage::on_lineEdit_returnPressed()
{
    ui->pushButton->click();
}
//搜索按钮
void searchPage::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text();
}
