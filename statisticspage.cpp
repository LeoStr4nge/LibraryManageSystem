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
    //读入数据
    borCEO.read();
    //禁止用户编辑表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<string> bookname = borCEO.getBooknames();
    vector<string> readername = borCEO.getReaders();
    vector<string> borrowDate = borCEO.getBorrowBookDates();
    vector<string> returnDate = borCEO.getReturnBookDates();
    for(int i = 0;i < vecbor.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::fromStdString(bookname[i])));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::fromStdString(readername[i])));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::fromStdString(borrowDate[i])));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::fromStdString(returnDate[i])));
    }
    int borrowCount = borCEO.getBorrowCount();
    QString temp = ui->labelBorrowed->text();
    temp += QString::number(borrowCount);
    ui->labelBorrowed->setText(temp);
    temp = ui->labelInLibrary->text();
    int inLibrary = vecbook.size();
    inLibrary -= borrowCount;
    temp += QString::number(inLibrary);
    ui->labelInLibrary->setText(temp);
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
