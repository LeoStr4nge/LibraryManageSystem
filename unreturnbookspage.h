#ifndef UNRETURNBOOKSPAGE_H
#define UNRETURNBOOKSPAGE_H

#include <QWidget>

namespace Ui {
class unreturnBooksPage;
}

class unreturnBooksPage : public QWidget
{
    Q_OBJECT

public:
    explicit unreturnBooksPage(QWidget *parent = nullptr);
    ~unreturnBooksPage();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::unreturnBooksPage *ui;
};

#endif // UNRETURNBOOKSPAGE_H
