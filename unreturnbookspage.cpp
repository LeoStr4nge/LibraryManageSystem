#include "unreturnbookspage.h"
#include "ui_unreturnbookspage.h"
#include "usercenter.h"
#include "book.h"
#include "date.h"
#include "borrow.h"
#include "user.h"
#include "dialog.h"

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
    string name = CEO.qName().toStdString();//用户名
    vector<string> temp = borCEO.borrower2ISBN(name);
    vector<int> unreturnedBooks;
    vector<int> borrowID = borCEO.getBorrowID(name);
    for (int i = 0;i < temp.size();i++) {
        int bookID = bookCEO.exactlySearch(temp[i]);
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
        //计算还书日期
        auto borrowDate = borCEO.borrowBookDate(vecbor[borrowID[i]]);//获取借书日期
        auto borrowTime = vecbor[borrowID[i]].getBorrowTime();//获取借书时间
        Date returnDate = borCEO.returnBookDate(borrowDate,borrowTime);//计算还书日期
        QString qReturnDate = QString::number(returnDate.year) + "年" + QString::number(returnDate.month) + "月" + QString::number(returnDate.day) + "日";//转换成Qt字符串
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(qReturnDate));
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
    int flag = borCEO.returnBook(name,ISBN,nowday);
    auto u = new unreturnBooksPage;//刷新页面
    u->show();
    if(flag == 1){
        DIALOGMSG = "还书成功";
    }else{
        DIALOGMSG = "还书失败";
    }
    auto d = new Dialog;
    d->show();
    this->close();
}
//一键归还
void unreturnBooksPage::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->rowCount();
    int flag;
    for(int i = 0;i < row;i++){
        std::string ISBN = ui->tableWidget->model()->index(i,1).data().toString().toStdString();
        string name = CEO.qName().toStdString();//名字
        Date nowday;
        flag = borCEO.returnBook(name,ISBN,nowday);
        auto u = new unreturnBooksPage;//刷新页面
        u->show();
    }
    if(flag == 1){
        DIALOGMSG = "还书成功";
    }else{
        DIALOGMSG = "还书失败";
    }
    auto d = new Dialog;
    d->show();
    this->close();
}

void unreturnBooksPage::on_pushButton_4_clicked()
{
    int bookID = ui->lineEdit->text().toInt();
    std::string ISBN = ui->tableWidget->model()->index(bookID - 1,1).data().toString().toStdString();//得到目标图书的ISBN
    int days = ui->comboBox->currentText().toInt();
    int flag = borCEO.renewBook(ISBN,days);
    auto u = new unreturnBooksPage;//刷新页面
    u->show();
    if(flag == 1){
        DIALOGMSG = "续借成功";
    }else{
        DIALOGMSG = "续借失败";
    }
    auto d = new Dialog;
    d->show();
    this->close();
}
