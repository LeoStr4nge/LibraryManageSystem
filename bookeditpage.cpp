#include "bookeditpage.h"
#include "ui_bookeditpage.h"
#include "adminpage.h"
#include "newbookpage.h"

bookEditPage::bookEditPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookEditPage)
{
    ui->setupUi(this);
}

bookEditPage::~bookEditPage()
{
    delete ui;
}

//返回按钮
void bookEditPage::on_pushButton_3_clicked()
{
    adminPage *p = new adminPage;
    p->show();
    this->close();
}

//新建书本页面
void bookEditPage::on_pushButton_2_clicked()
{
    newBookPage *n = new newBookPage;
    n->show();
    this->close();
}
