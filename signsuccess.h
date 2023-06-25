#ifndef SIGNSUCCESS_H
#define SIGNSUCCESS_H

#include <QDialog>

namespace Ui {
class signSuccess;
}

class signSuccess : public QDialog
{
    Q_OBJECT

public:
    explicit signSuccess(QWidget *parent = nullptr);
    ~signSuccess();

private:
    Ui::signSuccess *ui;
};

#endif // SIGNSUCCESS_H
