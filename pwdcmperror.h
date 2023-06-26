#ifndef PWDCMPERROR_H
#define PWDCMPERROR_H

#include <QDialog>

namespace Ui {
class pwdCmpError;
}

class pwdCmpError : public QDialog
{
    Q_OBJECT

public:
    explicit pwdCmpError(QWidget *parent = nullptr);
    ~pwdCmpError();

private:
    Ui::pwdCmpError *ui;
};

#endif // PWDCMPERROR_H
