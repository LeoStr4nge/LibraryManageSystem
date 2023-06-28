#include "newbookpage.h"
#include "ui_newbookpage.h"
#include "book.h"
#include "dialog.h"

extern vector<book> vecbook;
extern book bookCEO;
extern QString DIALOGMSG;

newBookPage::newBookPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newBookPage)
{
    ui->setupUi(this);
}

newBookPage::~newBookPage()
{
    delete ui;
}

void newBookPage::on_pushButton_clicked()
{
    std::string bookName =  ui->lineEditName->text().toStdString();
    std::string ISBN = ui->lineEditISBN->text().toStdString();
    std::string author = ui->lineEditAuthor->text().toStdString();
    std::string type = ui->comboBoxType->currentText().toStdString();
    std::string publisher = ui->lineEditPublisher->text().toStdString();

    //检查有无空白输入
    if(bookName.empty() || ISBN.empty() || author.empty() || type.empty() || publisher.empty()){
        DIALOGMSG = "请输入完整的信息";
        auto d = new Dialog;
        d->show();
    }else{
        int flag = 0;
        char temp = ISBN[1];
        if(temp != '-')
            flag = 1;
        temp = ISBN[6];
        if(temp != '-')
            flag = 1;
        temp = ISBN[11];
        if(temp != '-')
            flag = 1;
        if(flag == 1){
            DIALOGMSG = "ISBN号格式不正确";
            auto d = new Dialog;
            d->show();
        }else{
            flag = bookCEO.add(bookName,author,publisher,ISBN,type,-1);
            if(flag == 0){
                DIALOGMSG = "该书籍已存在";
                auto d = new Dialog;
                d->show();
            }
            else if(flag == 1){
                DIALOGMSG = "书籍添加成功";
                auto d = new Dialog;
                d->show();
            }
        }

    }

}

void newBookPage::on_lineEditISBN_returnPressed()
{
    string ISBN = ui->lineEditISBN->text().toStdString();
    if(ISBN.empty() || ISBN.size() != 10){
        DIALOGMSG = "请输入正确的ISBN号";
        auto d = new Dialog;
        d->show();
    }
    else if(ISBN.size() != 13){
        ISBN.insert(1,"-");
        ISBN.insert(6,"-");
        ISBN.insert(11,"-");
        QString temp = QString::fromStdString(ISBN);
        ui->lineEditISBN->setText(temp);
    }
}
