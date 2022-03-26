#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->main_customer_ops_form->setGeometry(10,10,431,411);

    //ui->main_customer_OPS->setStyleSheet("background-color:limegreen;");

    //
    //myforms.insert(ui->main_menu_buttons_form);

    myforms.insert(ui->main_customer_ops_form);
    myforms.insert(ui->main_money_ops_form);
    myforms.insert(ui->main_currency_ops_form);
    myforms.insert(ui->main_bills_form);
    myforms.insert(ui->main_insurance_form);
    myforms.insert(ui->main_investment_transactions_form);

    myforms.insert(ui->customer_ops_buttons_form);
    myforms.insert(ui->cs_customer_register_form);
    myforms.insert(ui->cs_remove_customer_form);
    myforms.insert(ui->cs_credit_check_form);
    myforms.insert(ui->cs_credit_payment_form);
    myforms.insert(ui->cs_Lend__form);
    

}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_cs_add_button_clicked()
{
    this->hide();
    ui->main_customer_ops_form->setVisible(true);
    ui->cs_customer_register_form->setGeometry(70,60,300,300);
    ui->cs_customer_register_form->setVisible(true);

}
void MainWindow::on_cs_remove_button_clicked()
{
    this->hide();
    ui->main_customer_ops_form->setVisible(true);
    ui->cs_remove_customer_form->setGeometry(70,60,300,300);
    ui->cs_remove_customer_form->setVisible(true);
}
void MainWindow::on_cs_credit_check_button_clicked()
{
    this->hide();
    ui->main_customer_ops_form->setVisible(true);
    ui->cs_credit_check_form->setGeometry(70,60,300,300);
    ui->cs_credit_check_form->setVisible(true);

}
void MainWindow::on_cs_credit_payment_button_clicked()
{
    this->hide();
    ui->main_customer_ops_form->setVisible(true);
    ui->cs_credit_payment_form->setGeometry(70,60,300,300);
    ui->cs_credit_payment_form->setVisible(true);
}
void MainWindow::on_cs_lend_button_clicked()
{
    this->hide();
    ui->main_customer_ops_form->setVisible(true);
    ui->cs_Lend__form->setGeometry(70,60,300,300);
    ui->cs_Lend__form->setVisible(true);
}



void MainWindow::on_main_money_transfer_button_clicked()
{
    this->hide();
    ui->main_money_ops_form->setGeometry(50,60,400,300);
    ui->main_money_ops_form->setVisible(true);
}
void MainWindow::on_main_bill_button_clicked()
{
    this->hide();
    ui->main_bills_form->setGeometry(70,60,300,300);
    ui->main_bills_form->setVisible(true);
}
void MainWindow::on_main_insurance_button_clicked()
{
    this->hide();
    ui->main_insurance_form->setGeometry(70,60,300,300);
    ui->main_insurance_form->setVisible(true);
}
void MainWindow::on_main_investment_button_clicked()
{
    this->hide();
    ui->main_investment_transactions_form->setGeometry(70,60,300,300);
    ui->main_investment_transactions_form->setVisible(true);
}
void MainWindow::on_main_customer_button_clicked()
{
    this->hide();
    ui->customer_ops_buttons_form->setGeometry(60,70,331,211);
    ui->customer_ops_buttons_form->setVisible(true);
    ui->main_customer_ops_form->setVisible(true);
}
void MainWindow::on_main_currency_button_clicked()
{
    this->hide();
    ui->main_currency_ops_form->setGeometry(70,60,300,300);
    ui->main_currency_ops_form->setVisible(true);
}
void MainWindow::on_Main_logout_clicked()
{
    QApplication::quit();
}

void MainWindow::on_cs_registerform_add_button_clicked()
{
    QString name=ui->cs_registerform_fullname_input->text();

    QString id=ui->cs_registerform_id_input->text();
    QString tel=ui->cs_registerform_tel_input->text();
    QString address=ui->cs_registerform_address_input->text();
    QString nation=ui->cs_registerform_nation_input->currentText();
    if(name=="" || id=="" || tel=="" || address==""){ QMessageBox::warning(this,"customer register","all information must be provided");}
    else{


    std::string sql="INSERT INTO CUSTOMERS (NATIONAL_ID,NAME,TEL,NATION,ADDRESS)"\
        "VALUES ("+id.toStdString()+",'"+name.toStdString()+"',"+tel.toStdString()+",'"+nation.toStdString()+"','"+address.toStdString()+"');";

//       std::string sql = "INSERT INTO CUSTOMERS (NATIONAL_ID,NAME,TEL,NATION,ADDRESS) "  \
//                "VALUES (1, 'Paul', 32, 'California', 20000.00 ); ";
//    qDebug()<<(const char*)&sql[0];
    this->db_set(sql);

    }


}


void MainWindow::on_cs_registerform_confirm_button_clicked()
{
     QString id=ui->cs_registerform_id_input->text();
     this->db_get(id.toStdString());
}

