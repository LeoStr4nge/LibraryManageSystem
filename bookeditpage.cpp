#include "bookeditpage.h"
#include "ui_bookeditpage.h"
#include "adminpage.h"
#include "newbookpage.h"
#include <vector>
#include "book.h"
#include "dialog.h"
#include "borrow.h"

extern std::vector<book> vecbook;
extern book bookCEO;
extern QString DIALOGMSG;
extern vector<borrow>vecbor;
extern borrow borCEO;

bookEditPage::bookEditPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookEditPage)
{
    ui->setupUi(this);
}

bookEditPage::~bookEditPage()
{
    delete ui;
}

//返回按钮
void bookEditPage::on_pushButton_3_clicked()
{
    adminPage *p = new adminPage;
    p->show();
    this->close();
}

//添加书本按钮
void bookEditPage::on_pushButton_2_clicked()
{
    newBookPage *n = new newBookPage;
    n->show();
    this->close();
}
//搜索按钮
void bookEditPage::on_pushButton_clicked()
{
    //清空表格
    ui->tableWidget->setRowCount(0);
    //搜索
    std::string s = ui->lineEdit->text().toStdString();
    std::vector<int> searchResult = bookCEO.sousuo(s);
    //ui->tableWidget->setColumnCount(result.size());
    for(int i = 0;i < searchResult.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(vecbook[searchResult[i]].qBookname()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(vecbook[searchResult[i]].qISBN()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(vecbook[searchResult[i]].qAuthor()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(vecbook[searchResult[i]].qPublisher()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(vecbook[searchResult[i]].qType()));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(vecbook[searchResult[i]].isExist()));
        string ISBN = vecbook[searchResult[i]].qISBN().toStdString();
        string returnDate = borCEO.haveISBN2huanshuday(ISBN);
        ui->tableWidget->setItem(row,6,new QTableWidgetItem(QString::fromStdString(returnDate)));
    }
    int row = ui->tableWidget->rowCount();
}
//保存修改按钮
void bookEditPage::on_pushButton_4_clicked()
{
    int row = ui->tableWidget->rowCount();
    int column = ui->tableWidget->columnCount();
    for(int i = 0;i < row;i++){
            string bookName = ui->tableWidget->model()->index(i,0).data().toString().toStdString();
            string ISBN = ui->tableWidget->model()->index(i,1).data().toString().toStdString();
            string author = ui->tableWidget->model()->index(i,2).data().toString().toStdString();
            string publisher = ui->tableWidget->model()->index(i,3).data().toString().toStdString();
            string type = ui->tableWidget->model()->index(i,4).data().toString().toStdString();
            int flagExist = ui->tableWidget->model()->index(i,5).data().toInt();
            int date = ui->tableWidget->model()->index(i,6).data().toInt();
            bookCEO.xiugai(bookName,author,publisher,ISBN,type,date,flagExist);
    }
    DIALOGMSG = "修改成功";
    ui->pushButton->click();
    auto d = new Dialog;
    d->show();
}
//回车触发搜索按钮
void bookEditPage::on_lineEdit_returnPressed()
{
    ui->pushButton->click();
}
//删除书籍
void bookEditPage::on_pushButton_5_clicked()
{
    int bookID = ui->lineEditBookID->text().toInt();
    string ISBN = ui->tableWidget->model()->index(bookID - 1,1).data().toString().toStdString();
    int flag = bookCEO.del(ISBN);
    ui->pushButton->click();
    if(flag == 1){
        DIALOGMSG = "删除成功";
        auto d = new Dialog;
        d->show();
    }else {
        DIALOGMSG = "删除失败";
        auto d = new Dialog;
        d->show();
}
}
