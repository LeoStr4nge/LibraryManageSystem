#include "statisticspage.h"
#include "ui_statisticspage.h"
#include "adminpage.h"

statisticsPage::statisticsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statisticsPage)
{
    ui->setupUi(this);
}

statisticsPage::~statisticsPage()
{
    delete ui;
}
//返回按钮
void statisticsPage::on_pushButton_clicked()
{
    auto a = new adminPage;
    a->show();
    this->close();
}
