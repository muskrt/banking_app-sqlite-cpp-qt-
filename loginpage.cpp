#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include <QPixmap>
loginPage::loginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPage)
{
    this->parent=parent;
    ui->setupUi(this);
    QPixmap px("C:/Users/mehme/OneDrive/Masaüstü/qtprojects/GUI3/login.ico");
    int w=ui->LoginPageIcon->width();
    int h=ui->LoginPageIcon->height();
    ui->LoginPageIcon->setPixmap(px.scaled(w,h,Qt::KeepAspectRatio));


}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_pushButton_clicked()
{

    QString user_name=ui->userName->text();
    QString pass_word=ui->Password->text();
    if(user_name=="mustafa"){
    parent->show();
    this->hide();
    }
    else{

        QMessageBox::warning(this,"Login","username os password not correct");
    }
}

