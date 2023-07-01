#ifndef STATISTICSPAGE_H
#define STATISTICSPAGE_H

#include <QWidget>

namespace Ui {
class statisticsPage;
}

class statisticsPage : public QWidget
{
    Q_OBJECT

public:
    explicit statisticsPage(QWidget *parent = nullptr);
    ~statisticsPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::statisticsPage *ui;
};

#endif // STATISTICSPAGE_H
