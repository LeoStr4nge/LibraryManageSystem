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

private:
    Ui::newBookPage *ui;
};

#endif // NEWBOOKPAGE_H
