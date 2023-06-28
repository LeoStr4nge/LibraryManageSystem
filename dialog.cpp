#include "dialog.h"
#include "ui_dialog.h"

QString DIALOGMSG;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText(DIALOGMSG);
}

Dialog::~Dialog()
{
    delete ui;
}
