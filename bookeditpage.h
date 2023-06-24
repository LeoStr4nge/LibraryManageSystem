#ifndef BOOKEDITPAGE_H
#define BOOKEDITPAGE_H

#include <QWidget>

namespace Ui {
class bookEditPage;
}

class bookEditPage : public QWidget
{
    Q_OBJECT

public:
    explicit bookEditPage(QWidget *parent = nullptr);
    ~bookEditPage();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::bookEditPage *ui;
};

#endif // BOOKEDITPAGE_H
