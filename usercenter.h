#ifndef USERCENTER_H
#define USERCENTER_H

#include <QWidget>

namespace Ui {
class userCenter;
}

class userCenter : public QWidget
{
    Q_OBJECT

public:
    explicit userCenter(QWidget *parent = nullptr);
    ~userCenter();

private slots:
    void on_pushButton_clicked();

private:
    Ui::userCenter *ui;
};

#endif // USERCENTER_H
