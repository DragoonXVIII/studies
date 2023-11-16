
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dzialanie->hide();
    ui->liczba1->hide();
    ui->liczba2->hide();
    ui->oblicz->hide();
    ui->wynik->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_oblicz_clicked()
{
    float wynik,
    a = (ui->liczba1->text()).toFloat(),
    b = (ui->liczba2->text()).toFloat();

    //qDebug()<<a<<b;

    switch(ui->dzialanie->currentIndex())
    {
        case 0:
            wynik = (a+b);
            break;
        case 1:
            wynik = (a-b);
            break;
        case 2:
            wynik = (a*b);
            break;
        case 3:
            wynik = (a/b);
            break;
    }

    ui->wynik->setText(QString::number(wynik, 'f', 2));
}


void MainWindow::on_pokazautora_ChcBx_stateChanged(int arg1)
{
    if(arg1)
        ui->autor->setText("DragonXVIII");
    else
        ui->autor->setText("<autor>");
}

/*void MainWindow::on_pokazautora_ChcBx_stateChanged(int arg1)
{

}*/


void MainWindow::on_calendarWidget_selectionChanged()
{
    ui->label->setText(QString((ui->calendarWidget->selectedDate()).toString()));
}


void MainWindow::on_pushButton_clicked()
{
    QString nazwisko = ui->lineEdit->text();
    ui->textEdit->append(nazwisko);
}


void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    ui->label_4->setText(QString::number(ui->horizontalSlider->value()));
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit_2->text() != nullptr)
    {
        ui->listWidget->addItem(ui->lineEdit_2->text());
        ui->label_8->setText(QString::number((ui->label_8->text()).toInt()+1)); //pozycje
        ui->label_10->setText(QString::number((ui->label_10->text().toInt() + ui->lineEdit_2->text().toInt())));
        ui->lineEdit_2->clear();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    ui->label_8->setText("0");
    ui->label_10->setText("0");
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->addItem(QString::number(ui->spinBox->value()));
    ui->label_8->setText(QString::number((ui->label_8->text()).toInt()+1)); //pozycje
    ui->label_10->setText(QString::number((ui->label_10->text().toInt() + ui->spinBox->value())));
}


void MainWindow::on_pushButton_5_clicked()
{
    QFile file("notes.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_pushButton_6_clicked()
{
    QFile file("notes.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    QString myText = in.readAll();
    ui->textEdit->setPlainText(myText);
    file.close();
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->clear();
}


void MainWindow::on_radioButton_clicked()
{
    this->setStyleSheet("background-color: red");
}


void MainWindow::on_radioButton_2_clicked()
{
    this->setStyleSheet("background-color: green");
}


void MainWindow::on_radioButton_3_clicked()
{
    this->setStyleSheet("background-color: blue");
}

void MainWindow::on_actionKopiuj_triggered()
{
    this->schowek = ui->textEdit->toPlainText();
}

void MainWindow::on_actionWytnij_triggered()
{
    this->schowek = ui->textEdit->toPlainText();
    ui->textEdit->clear();
}

void MainWindow::on_actionWklej_triggered()
{
    ui->textEdit->append(schowek);
}

void MainWindow::on_actionk1_triggered()
{
    QMessageBox::information(this,"Komunikat 1","informacja");
}

void MainWindow::on_actionk2_triggered()
{
    QMessageBox::warning(this,"Komunikat 1","ostrzezenie",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
        QMessageBox::Yes);
}
