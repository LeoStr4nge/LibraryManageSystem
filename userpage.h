#ifndef USERPAGE_H
#define USERPAGE_H

#include <QWidget>

namespace Ui {
class userPage;
}

class userPage : public QWidget
{
    Q_OBJECT

public:
    explicit userPage(QWidget *parent = nullptr);
    ~userPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::userPage *ui;
};

#endif // USERPAGE_H
