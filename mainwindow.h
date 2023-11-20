#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addinfo.h>
#include <QtSql>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <retrive.h>
#include <tableview.h>
#include <update.h>
#include <delete.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase mydb;
    bool openconnection(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        //mydb.setDatabaseName("D:/Entertainment/code/QT/Student_Data_Management/Database/StudentsInfo.db");
        mydb.setDatabaseName("D:\qt dwnload\AcademicPulse-master\AcademicPulse-master\Database\StudentsInfo.db");
        if(mydb.open()){
            ui->statusbar->showMessage("Database succesfully connected!!!",5000);
            return true;
        }
        else{
            ui->statusbar->showMessage("Failed to open database!!!",5000);
            return false;
        }

    }
    void closeconnection(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
private slots:
    void on_pushButton_clicked();

    void on_pushButton_retrive_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_showAll_clicked();

    void on_pushButton_modify_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
