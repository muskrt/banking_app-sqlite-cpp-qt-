#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpage.h"
#include <list>
#include <iostream>
#include <string>
#include <set>
#include <sqlite3.h>
#include <QGroupBox>
#include <typeinfo>
#include <QDebug>
#include <QMessageBox>
#include<QDir>
#include <QFile>
static std::string sql_colums;
static std::string sql_record;

static int callback(void *data , int argc, char **argv, char **azColName) {
   int i;


   qDebug()<<(const char*)(data);
   std::string columns; std::string get_data;
   for(i = 0; i<argc; i++) {
      sql_colums += azColName[i];
     sql_colums +=" ";
      sql_record+=(argv[i] ? argv[i] : "NULL");
      sql_record+=" ";
   }

   return 0;
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void login(){
        this->hide();
        login_page->setWindowTitle("myapp Login");

        login_page->show();
    }


    void db_get(std::string national_id){

        char* err;
        std::string sql=("SELECT * FROM CUSTOMERS WHERE NATIONAL_ID = "+national_id+";");
        const char* data="--------------------Dabase Bank.db--------------:";
        sqlite3_exec(Db, (const char* )&sql[0], callback, (void*)data, &err);
        qDebug()<<&sql_colums[0];
        qDebug()<<&sql_record[0];
        sql_colums=" ";
        sql_record=" ";

//        const char** mystring;
//        std::string test[]{"welcome again sir" };
//        mystring[0]=&test[0][0];
//        const char* mysecond="pointer test";

//        qDebug()<<QString(mystring[0]);
//    mystring[1]=&mysecond[0];
//        qDebug()<<QString(mystring[1]);
//int myarray[3][2]={{1,2},{3,4},{5,6}};
//int** p;
//p[0]=&myarray[0][0];
//p[1]=&myarray[1][0];

//qDebug()<<QString(typeid(p[0]).name());

    }
    void db_check(){
        //check if db exists
        QFile file("Bank.db");
        if(file.exists()){
        qDebug()<<"db test";
        int rc=sqlite3_open("Bank.db",&Db);
        if(rc){
            QMessageBox::warning(this,"database access","cant access to database");
        }
        }
        else{

        sqlite3_open("Bank.db",&Db);
        char* err;
        const char* sql="CREATE TABLE CUSTOMERS("
                        "NATIONAL_ID TEXT PRIMARY KEY     NOT NULL,"
                        "NAME           TEXT    NOT NULL,"
                        "TEL            TEXT     NOT NULL,"
                        "NATION         TEXT    NOT NULL,"
                        "ADDRESS        CHAR(50));";


            int rc = sqlite3_exec(Db, sql, 0, 0, &err);
            if(rc) QMessageBox::warning(this,"database access","cant create database");
            sql="CREATE TABLE ACCOUNT("
                    "NATIONAL_ID TEXT PRIMARY KEY NOT NULL,"
                    "ACCOUNT_NO TEXT NOT NULL,"
                    "DEBT REAL ,"
                    "MONEY REAL);";
            rc=sqlite3_exec(Db,sql,0,0,&err);
            if(rc) QMessageBox::warning(this,"database access","cant create database");


        }



    }




bool db_set(std::string sql_command){
    char* err;
    int rc;
    qDebug()<<(const char*)&sql_command[0];
    char * data="insert test";
    rc=sqlite3_exec(Db,(const char*)&sql_command[0],0,0,&err);
    if(rc) {qDebug()<<"cant insert"; qDebug()<<err;}
    //sqlite3_exec(Db,"SELECT * FROM CUSTOMERS",callback,(void*)data,&err);
    return rc;
}

    void hide(){

        for(QGroupBox* x: myforms) x->setVisible(false);
    }


    ~MainWindow();

private slots:


    void on_Main_logout_clicked();



    void on_cs_add_button_clicked();

    void on_cs_remove_button_clicked();

    void on_cs_credit_check_button_clicked();

    void on_cs_credit_payment_button_clicked();

    void on_cs_lend_button_clicked();



    void on_main_money_transfer_button_clicked();

    void on_main_bill_button_clicked();

    void on_main_insurance_button_clicked();

    void on_main_investment_button_clicked();

    void on_main_customer_button_clicked();

    void on_main_currency_button_clicked();

    void on_cs_registerform_add_button_clicked();

    void on_cs_registerform_confirm_button_clicked();

private:
    sqlite3* Db;

    std::set<QGroupBox*> myforms;
    Ui::MainWindow *ui;
    loginPage* login_page=new loginPage(this);

};
#endif // MAINWINDOW_H
