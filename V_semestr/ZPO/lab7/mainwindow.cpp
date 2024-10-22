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

void MainWindow::on_addButton_released()
{
    if( ui->brandLine->text().isEmpty() ||
        ui->modelLine->text().isEmpty() ||
        ui->productionLine->text().isEmpty() ||
        ui->vinLine->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę uzupełnić wszystkie pola.");
        return;
    }
    bool ok;
    int productionYear = ui->productionLine->text().toInt(&ok);
    if(!ok)
    {
       QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać liczbę całkowitą.");
    }
    else
    {
        bool ok = catalog.addCar(Car(ui->brandLine->text(),
                           ui->modelLine->text(),
                           productionYear,
                           ui->vinLine->text())); //QString brand, QString model, int yearOfProduction, QString vim
        if(!ok)
        {
            QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Samochod o podanym numerze VIN już istnieje.");
            return;
        }
        ui->listWidget->clear();
        loadCatalog();
        qDebug()<<"Car added";
    }
    return;
}


void MainWindow::on_deleteButton_released()
{

    if(ui->vinLine->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać poprawny numer VIN.");
        return;
    }
    bool ok = catalog.deleteCar(ui->deleteLine->text());
    if(!ok)
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać poprawny numer VIN.");
        return;
    }
    ui->listWidget->clear();
    loadCatalog();
    qDebug()<<"Car deleted";
    return;
}


void MainWindow::on_countButton_released()
{
    if(ui->countLine->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać poprawny rok produkcji.");
        return;
    }
    int counter = catalog.countC(ui->countLine->text().toInt());
    QMessageBox::information(this, "Info", "Znaleziono: "+ QString::number(counter)+ " samochodów");
}

void MainWindow::loadCatalog()
{
    ui->listWidget->clear();
    for(const auto &car: catalog.getCars())
    {
        ui->listWidget->addItem(car.getInfo());
    }
}

void MainWindow::on_sortY_released()
{
    catalog.sortY();
    ui->listWidget->clear();
    loadCatalog();
}


void MainWindow::on_sortA_released()
{
    catalog.sortA();
    ui->listWidget->clear();
    loadCatalog();
}

