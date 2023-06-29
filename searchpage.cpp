#include "searchpage.h"
#include "ui_searchpage.h"
#include "userpage.h"
#include <string>
#include "book.h"
#include "dialog.h"

extern vector<book> vecbook;
extern book bookCEO;
extern QString DIALOGMSG;

searchPage::searchPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
    //禁止用户编辑表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置序号的非法输入
    QRegExp regx("[0-9]");
    QValidator *validator = new QRegExpValidator(regx,ui->lineEditBorrow);
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
    string s = ui->lineEditSearch->text().toStdString();
    vector<int> searchResult = bookCEO.sousuo(s);
    //ui->tableWidget->setColumnCount(result.size());
    for(int i = 0;i < searchResult.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(vecbook[searchResult[i]].qBookname()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(vecbook[searchResult[i]].qISBN()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(vecbook[searchResult[i]].qAuthor()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(vecbook[searchResult[i]].qPublisher()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(vecbook[searchResult[i]].qType()));
        //暂时还没有还书时间可供显示
        //ui->tableWidget->setItem(row,5,new QTableWidgetItem(vecbook[searchResult[i]].qAuthor()));
    }
}

void searchPage::on_pushButton_3_clicked()
{
    int bookID = ui->lineEditBorrow->text().toInt();
    string value = ui->tableWidget->model()->index(bookID - 1,1).data().toString().toStdString();
    //需要一个接收书码并返回1/0/-1表示是否借书成功/该书已被借阅的借阅函数
}
