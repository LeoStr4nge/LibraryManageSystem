#include "statisticspage.h"
#include "ui_statisticspage.h"
#include "adminpage.h"
#include "book.h"
#include "borrow.h"
#include "dialog.h"

extern vector<book> vecbook;
extern book bookCEO;
extern vector<borrow>vecbor;
extern borrow borCEO;
extern User CEO;
extern QString DIALOGMSG;
statisticsPage::statisticsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statisticsPage)
{
    ui->setupUi(this);
    //禁止用户编辑表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0;i < vecbor.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem());//未完成，需要一个返回string数组类型用户名，书名以及借阅时间，归还时间的函数
    }
}

statisticsPage::~statisticsPage()
{
    delete ui;
}
//返回按钮
void statisticsPage::on_pushButton_clicked()
{
    auto a = new adminPage;
    a->show();
    this->close();
}
