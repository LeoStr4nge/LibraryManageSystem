#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>

namespace Ui {
class searchPage;
}

class searchPage : public QWidget
{
    Q_OBJECT

public:
    explicit searchPage(QWidget *parent = nullptr);
    ~searchPage();

private slots:
    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::searchPage *ui;
};

#endif // SEARCHPAGE_H
