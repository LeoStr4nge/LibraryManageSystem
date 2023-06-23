#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FirstWindow; }
QT_END_NAMESPACE

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

private:
    Ui::FirstWindow *ui;
};
#endif // FIRSTWINDOW_H
