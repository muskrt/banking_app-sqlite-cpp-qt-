#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class loginPage;
}

class loginPage : public QDialog
{
    Q_OBJECT

public:
    explicit loginPage(QWidget *parent = nullptr);
    ~loginPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginPage *ui;
    QWidget* parent;
};

#endif // LOGINPAGE_H
