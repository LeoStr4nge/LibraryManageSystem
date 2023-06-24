#include "userpage.h"
#include "ui_userpage.h"
#include "searchpage.h"
#include "ui_searchpage.h"

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
