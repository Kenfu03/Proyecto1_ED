#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Struct.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap myPix = QPixmap("C:\\Users\\Kenneth Fuentes\\Documents\\GitHub\\Proyecto1_ED\\Img\\interfaz.png");
    ui->label->setPixmap(myPix);
    ui->label->show();

    ui->conCarrito->setHidden(true);
    ui->conMez1->setHidden(true);
    ui->conMez2->setHidden(true);
    ui->conMezCho->setHidden(true);
    ui->conBandMez->setHidden(true);
    ui->conBandCho->setHidden(true);
    ui->conEnsam->setHidden(true);
    ui->conHorno->setHidden(true);
    ui->conBand->setHidden(true);
    ui->conSup1->setHidden(true);
    ui->conSup2->setHidden(true);
    ui->conEmpaca->setHidden(true);
    ui->apliCambio->setHidden(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_modMaqui_clicked()
{
    ui->conCarrito->setHidden(false);
    ui->conMez1->setHidden(false);
    ui->conMez2->setHidden(false);
    ui->conMezCho->setHidden(false);
    ui->conBandMez->setHidden(false);
    ui->conBandCho->setHidden(false);
    ui->conEnsam->setHidden(false);
    ui->conHorno->setHidden(false);
    ui->conBand->setHidden(false);
    ui->conSup1->setHidden(false);
    ui->conSup2->setHidden(false);
    ui->conEmpaca->setHidden(false);

    ui->startEjec->setVisible(false);
    ui->modMaqui->setVisible(false);
    ui->apliCambio->setHidden(false);
}


void MainWindow::on_apliCambio_clicked()
{
    ui->conCarrito->setHidden(true);
    ui->conMez1->setHidden(true);
    ui->conMez2->setHidden(true);
    ui->conMezCho->setHidden(true);
    ui->conBandMez->setHidden(true);
    ui->conBandCho->setHidden(true);
    ui->conEnsam->setHidden(true);
    ui->conHorno->setHidden(true);
    ui->conBand->setHidden(true);
    ui->conSup1->setHidden(true);
    ui->conSup2->setHidden(true);
    ui->conEmpaca->setHidden(true);

    ui->startEjec->setVisible(true);
    ui->modMaqui->setVisible(true);
    ui->apliCambio->setVisible(false);
}

void MainWindow::on_startEjec_clicked()
{
    QString tito = ui->InTito->text();
    QString te = ui->InTe->text();
    QString tubo = ui->InTubo->text();
    int n1 = tito.toInt();
    int n2 = te.toInt();
    int n3 = tubo.toInt();

    int capMez1 = ui->conMez1->text().toInt();
    int capMez2 = ui->conMez2->text().toInt();
    int capMezCho = ui->conMezCho->text().toInt();
    int capCarrito = ui->conCarrito->text().toInt();

    planificador * pl = new planificador(n1, n2, n3, capMez1, capMez2, capMezCho, capCarrito);
    int total = pl->totalGalle();
    QString _total = QString::number(total);
    ui->resTotal->setText(_total);

    ui->InTito->setEnabled(false);
    ui->InTe->setEnabled(false);
    ui->InTubo->setEnabled(false);
    ui->InChoc->setEnabled(false);
    ui->Inmasa->setEnabled(false);

    ui->startEjec->setVisible(false);
    ui->modMaqui->setVisible(false);
    ui->apliCambio->setVisible(false);
}

void MainWindow::on_stopEjec_clicked()
{
    ui->InTito->setEnabled(true);
    ui->InTe->setEnabled(true);
    ui->InTubo->setEnabled(true);
    ui->InChoc->setEnabled(true);
    ui->Inmasa->setEnabled(true);

    ui->startEjec->setVisible(true);
    ui->modMaqui->setVisible(true);
}
