#include "pwderror.h"
#include "ui_pwderror.h"

pwdError::pwdError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pwdError)
{
    ui->setupUi(this);
}

pwdError::~pwdError()
{
    delete ui;
}

void pwdError::on_buttonBox_accepted()
{
    this->close();
}

void pwdError::on_buttonBox_rejected()
{
    this->close();
}
