#ifndef PWDERROR_H
#define PWDERROR_H

#include <QDialog>

namespace Ui {
class pwdError;
}

class pwdError : public QDialog
{
    Q_OBJECT

public:
    explicit pwdError(QWidget *parent = nullptr);
    ~pwdError();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::pwdError *ui;
};

#endif // PWDERROR_H
