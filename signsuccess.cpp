#include "signsuccess.h"
#include "ui_signsuccess.h"

signSuccess::signSuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signSuccess)
{
    ui->setupUi(this);
}

signSuccess::~signSuccess()
{
    delete ui;
}
