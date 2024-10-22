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



void MainWindow::loadTable()
{
    ui->listWidget_2->clear();
    QMap <QString, int> data = table.reload(0);
    if(ui->showPeopleNumbers->isChecked())
    {
        for(const QString &country : data.keys())
        {
            ui->listWidget_2->addItem(QString(country+" "+QString::number(data.value(country))));
        }
    }
    else
    {
        for(const QString &country : data.keys())
        {
            ui->listWidget_2->addItem(country);
        }
    }
}

void MainWindow::on_addCountryButton_released()
{
    if(ui->countryLineAdd->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać nazwę państwa.");
        return;
    }
    bool ok = table.addCountry(ui->countryLineAdd->text(),
                               ui->peopleLine->text().toInt());
    if(!ok)
    {
        QMessageBox::warning(this, "Błąd", "Państwo widnieje już w katalogu.");
        return;
    }
    ui->listWidget_2->clear();
    loadTable();
    qDebug()<<"Country added";
    return;
}

void MainWindow::on_deleteCountryButton_released()
{
    if(ui->countryLineAdd->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać nazwę państwa.");
        return;
    }
    bool ok = table.deleteCountry(ui->countryLineDel->text());
    if(!ok)
    {
        QMessageBox::warning(this, "Błąd", "Państwo nie widnieje w katalogu.");
        return;
    }
    ui->listWidget_2->clear();
    loadTable();
    qDebug()<<"Country deleted";
    return;
}

void MainWindow::on_showPeopleNumbers_released()
{
    ui->listWidget_2->clear();
    loadTable();
}

void MainWindow::on_sortIButton_released()
{
    ui->listWidget_2->clear();
    QVector<QPair<QString, int>> data = table.sortPopulationAscending();
    if(ui->showPeopleNumbers->isChecked())
    {
        for(const auto &pair : data)
        {
            ui->listWidget_2->addItem(pair.first + " " + QString::number(pair.second));
        }
    }
    else
    {
        for (const auto &pair : data)
        {
            ui->listWidget_2->addItem(pair.first);
        }
    }
}

void MainWindow::on_sortDButton_released()
{
    ui->listWidget_2->clear();
    QVector<QPair<QString, int>> data = table.sortPopulationDescending();
    if(ui->showPeopleNumbers->isChecked())
    {
        for(const auto &pair : data)
        {
            ui->listWidget_2->addItem(pair.first + " " + QString::number(pair.second));
        }
    }
    else
    {
        for (const auto &pair : data)
        {
            ui->listWidget_2->addItem(pair.first);
        }
    }
}

void MainWindow::on_deleteCountryButton_2_released()
{
    if(ui->range1Line->text().isEmpty() || ui->range1Line->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość! Proszę podać ilość mieszkańców.");
        return;
    };
    ui->listWidget_2->clear();
    QMap<QString, int> table2 = table.reload(ui->range1Line->text().toInt(), ui->range2line->text().toInt());
    if(ui->showPeopleNumbers->isChecked())
    {
        for(const QString &country : table2.keys())
        {
            ui->listWidget_2->addItem(QString(country+" "+QString::number(table2.value(country))));
        }
    }
    else
    {
        for(const QString &country : table2.keys())
        {
            ui->listWidget_2->addItem(country);
        }
    }
    return;
}

