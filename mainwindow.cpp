#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString tito = ui->lineEdit->text();
    QString te = ui->lineEdit_2->text();
    QString tubo = ui->lineEdit_3->text();
    int n1 = tito.toInt();
    int n2 = tito.toInt();
    int n3 = tito.toInt();


}
