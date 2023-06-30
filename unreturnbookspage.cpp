#include "unreturnbookspage.h"
#include "ui_unreturnbookspage.h"
#include "usercenter.h"

unreturnBooksPage::unreturnBooksPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::unreturnBooksPage)
{
    ui->setupUi(this);
}

unreturnBooksPage::~unreturnBooksPage()
{
    delete ui;
}

void unreturnBooksPage::on_pushButton_3_clicked()
{
    auto u = new userCenter;
    u->show();
    this->close();
}
