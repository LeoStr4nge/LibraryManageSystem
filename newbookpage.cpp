#include "newbookpage.h"
#include "ui_newbookpage.h"

newBookPage::newBookPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newBookPage)
{
    ui->setupUi(this);
}

newBookPage::~newBookPage()
{
    delete ui;
}
