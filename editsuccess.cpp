#include "editsuccess.h"
#include "ui_editsuccess.h"

editSuccess::editSuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editSuccess)
{
    ui->setupUi(this);
}

editSuccess::~editSuccess()
{
    delete ui;
}
