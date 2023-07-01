#include "unreturnbookspage.h"
#include "ui_unreturnbookspage.h"
#include "usercenter.h"

unreturnBooksPage::unreturnBooksPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::unreturnBooksPage)
{
    ui->setupUi(this);
    //禁止用户编辑表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置序号的非法输入
    QRegExp regx("[0-9]");
    QValidator *validator = new QRegExpValidator(regx,ui->lineEdit);
    ui->lineEdit->setValidator(validator);
}

unreturnBooksPage::~unreturnBooksPage()
{
    delete ui;
}
//返回按钮
void unreturnBooksPage::on_pushButton_3_clicked()
{
    auto u = new userCenter;
    u->show();
    this->close();
}
//还书按钮
void unreturnBooksPage::on_pushButton_clicked()
{
    int bookID = ui->lineEdit->text().toInt();
    std::string ISBN = ui->tableWidget->model()->index(bookID - 1,1).data().toString().toStdString();//得到目标图书的ISBN
    //需要一个根据ISBN号归还图书，并返回1/0表示是否归还成功的函数
}
//一键归还
void unreturnBooksPage::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->rowCount();
    for(int i = 0;i < row;i++){
        std::string ISBN = ui->tableWidget->model()->index(i,1).data().toString().toStdString();
        //需要一个根据ISBN号归还图书，并返回1/0表示是否归还成功的函数
    }
}
