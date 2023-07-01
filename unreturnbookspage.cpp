#include "unreturnbookspage.h"
#include "ui_unreturnbookspage.h"
#include "usercenter.h"
#include "book.h"
#include "date.h"
#include "borrow.h"
#include "user.h"

extern vector<book> vecbook;
extern book bookCEO;
extern vector<borrow>vecbor;
extern borrow borCEO;
extern User CEO;
extern QString DIALOGMSG;

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
    //显示未归还的图书
    string name = CEO.qName().toStdString();
    vector<string> temp = borCEO.gerenjieshuxinxi(name);
    vector<int> unreturnedBooks;
    for (int i = 0;i < temp.size();i++) {
        int bookID = bookCEO.exactSearch(temp[i]);
       unreturnedBooks.push_back(bookID);
    }
    for(int i = 0;i < unreturnedBooks.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(vecbook[unreturnedBooks[i]].qBookname()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(vecbook[unreturnedBooks[i]].qISBN()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(vecbook[unreturnedBooks[i]].qAuthor()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(vecbook[unreturnedBooks[i]].qPublisher()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(vecbook[unreturnedBooks[i]].qType()));
        //暂时没有还书日期可以显示
        //ui->tableWidget->setItem(row,5,new QTableWidgetItem());
    }
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
    string name = CEO.qName().toStdString();//名字
    Date nowday;
    borCEO.huanshu(name,ISBN,nowday);

}
//一键归还
void unreturnBooksPage::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->rowCount();
    for(int i = 0;i < row;i++){
        std::string ISBN = ui->tableWidget->model()->index(i,1).data().toString().toStdString();
        //需要一个根据ISBN号归还图书，并返回1/0表示是否归还成功的函数
        string name = CEO.qName().toStdString();//名字
        Date nowday;
        borCEO.huanshu(name,ISBN,nowday);
    }
}
