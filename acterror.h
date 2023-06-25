#ifndef ACTERROR_H
#define ACTERROR_H

#include <QDialog>

namespace Ui {
class actError;
}

class actError : public QDialog
{
    Q_OBJECT

public:
    explicit actError(QWidget *parent = nullptr);
    ~actError();

private:
    Ui::actError *ui;
};

#endif // ACTERROR_H
