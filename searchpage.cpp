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
    string s = ui->lineEdit->text().toStdString();
    vector<int> result = bookCEO.sousuo(s);
    //ui->tableWidget->setColumnCount(result.size());
    for(int i = 0;i < result.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(vecbook[result[i]].qBookname()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(vecbook[result[i]].qISBN()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(vecbook[result[i]].qAuthor()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(vecbook[result[i]].qPublisher()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(vecbook[result[i]].qType()));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(vecbook[result[i]].qAuthor()));
    }

}
