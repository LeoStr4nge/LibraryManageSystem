#include "searchpage.h"
#include "ui_searchpage.h"
#include "userpage.h"

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

void searchPage::on_pushButton_2_clicked()
{
    userPage* n = new userPage;
    n->show();
    this->close();
}

void searchPage::on_lineEdit_returnPressed()
{
    ui->pushButton->click();
}
