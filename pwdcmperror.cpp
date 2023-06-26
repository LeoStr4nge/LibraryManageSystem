#include "pwdcmperror.h"
#include "ui_pwdcmperror.h"

pwdCmpError::pwdCmpError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pwdCmpError)
{
    ui->setupUi(this);
}

pwdCmpError::~pwdCmpError()
{
    delete ui;
}
