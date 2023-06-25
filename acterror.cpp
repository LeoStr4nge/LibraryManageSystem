#include "acterror.h"
#include "ui_acterror.h"

actError::actError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::actError)
{
    ui->setupUi(this);
}

actError::~actError()
{
    delete ui;
}
