#ifndef EDITSUCCESS_H
#define EDITSUCCESS_H

#include <QDialog>

namespace Ui {
class editSuccess;
}

class editSuccess : public QDialog
{
    Q_OBJECT

public:
    explicit editSuccess(QWidget *parent = nullptr);
    ~editSuccess();

private:
    Ui::editSuccess *ui;
};

#endif // EDITSUCCESS_H
