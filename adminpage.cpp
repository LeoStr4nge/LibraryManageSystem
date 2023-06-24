#include "adminpage.h"
#include "ui_adminpage.h"
#include "bookeditpage.h"

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

void adminPage::on_pushButton_clicked()
{
    bookEditPage *b = new bookEditPage;
    b->show();
    this->close();
}
