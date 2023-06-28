#ifndef NEWBOOKPAGE_H
#define NEWBOOKPAGE_H

#include <QWidget>

namespace Ui {
class newBookPage;
}

class newBookPage : public QWidget
{
    Q_OBJECT

public:
    explicit newBookPage(QWidget *parent = nullptr);
    ~newBookPage();

private slots:
    void on_pushButton_clicked();

    void on_lineEditISBN_returnPressed();

private:
    Ui::newBookPage *ui;
};

#endif // NEWBOOKPAGE_H
