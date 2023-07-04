#include "searchpage.h"
#include "ui_searchpage.h"
#include "userpage.h"
#include <string>
#include "book.h"
#include "dialog.h"
#include "borrow.h"
#include "user.h"
#include "date.h"

extern vector<book> vecbook;
extern book bookCEO;
extern QString DIALOGMSG;
extern vector<borrow>vecbor;
extern borrow borCEO;
extern User CEO;

searchPage::searchPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
    //禁止用户编辑表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置序号的非法输入
    QRegularExpression regx("[0-9]");
    QValidator *validator = new QRegularExpressionValidator(regx,ui->lineEditBorrow);
    ui->lineEditBorrow->setValidator(validator);
}

searchPage::~searchPage()
{
    delete ui;
}

//返回按钮
void searchPage::on_pushButton_2_clicked()
{
    userPage* n = new userPage;
    n->show();
    this->close();
}
//回车绑定按钮
void searchPage::on_lineEdit_returnPressed()
{
    ui->pushButton->click();
}
//搜索按钮
void searchPage::on_pushButton_clicked()
{
    //清空表格
    ui->tableWidget->setRowCount(0);
    //搜索
    string s = ui->lineEditSearch->text().toStdString();
    vector<int> searchResult = bookCEO.search(s);
    for(int i = 0;i < searchResult.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(vecbook[searchResult[i]].qBookname()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(vecbook[searchResult[i]].qISBN()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(vecbook[searchResult[i]].qAuthor()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(vecbook[searchResult[i]].qPublisher()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(vecbook[searchResult[i]].qType()));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(vecbook[searchResult[i]].isExist()));
    }
}
//借阅
void searchPage::on_pushButton_3_clicked()
{
    int bookID = ui->lineEditBorrow->text().toInt();
    string ISBN = ui->tableWidget->model()->index(bookID - 1,1).data().toString().toStdString();
    string name = CEO.qName().toStdString();
    Date now;
    int Days = ui->comboBox->currentText().toUInt();
    int flag = borCEO.borrowBook(name,ISBN,now,Days);
    ui->pushButton->click();
    if(flag == 0){
        DIALOGMSG = "该书已被借出";
    }
    else if(flag == 1){
        DIALOGMSG = "借阅成功";
    }else{
        DIALOGMSG = "借书失败";
    }
    auto d = new Dialog;
    d->show();
}
