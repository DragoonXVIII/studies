
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <random>
#include <QThread>
#include <QMessageBox>
#include <QFile>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    ui->horizontalSlider->setRange(0,32);
    ui->sliderValue->setText(QString::number(ui->horizontalSlider->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked() //oblicz kalkulator lotu
{

    QString currentBatterryAmountStr = ui->typeofAcumulator->currentText();
    currentBatterryAmountStr.chop(4);
    currentBatterryAmount = currentBatterryAmountStr.toInt();
    currentBspModel = ui->bspModel->currentText();
    currentBatterryNumber = ui->nofAcumulators->value();

    qDebug()<< currentBspModel<< ", ";

    switch(currentBatterryAmount)
    {
        case 3000:
        {
            if(currentBspModel == "Mavic Air 2")
            {
                currentBatteryTime = 25;

            }

            if(currentBspModel == "Mini 3 Pro")
            {
                currentBatteryTime = 30;
                qDebug()<<"nominal battery time: "<<30;
            }

            break;
        }

        case 3500:
        {
            if(currentBspModel == "Mavic Air 2")
            {
                currentBatteryTime = 30;
                qDebug()<<"nominal battery time: "<<30;
            }

            if(currentBspModel == "Mini 3 Pro")
            {
                currentBatteryTime = 35;
            }

            break;
        }

        case 4500:
        {
            if(currentBspModel == "Mavic Air 2")
            {
                currentBatteryTime = 35;
            }

            if(currentBspModel == "Mini 3 Pro")
            {
                currentBatteryTime = 40;
            }
            break;
        }
    }

    switch(ui->flightMode->currentIndex())
    {
        case 0:
        {
            qDebug()<< "flight mode: eco";
            currentBatteryTime += 5;
            break;
        }

        case 1:
        {
            qDebug()<< "flight mode: normal";
            currentBatteryTime += 0;
            break;
        }

        case 2:
        {
            qDebug()<< "flight mode: sport";
            currentBatteryTime -= 5;
            break;
        }
    }

    int time = (currentBatteryTime * currentBatterryNumber) + ui->nofAcumulators->value();
    int timeh = time/60, timem = time%60;
    qDebug()<< "hours: " + QString::number(timeh) + " minutes: " + QString::number(timem);

    QTime selectedTime = ui->hourOfBeggining->time();
    int hours = selectedTime.hour();
    int minutes = selectedTime.minute();

    timem += minutes;
    if(timem>60)
    {
        timeh ++;
        timem %= 60;
    }
    timeh += hours;
    qDebug()<< QString::number(timeh) + ":" + QString::number(timem);
    ui->hourOfLanding->setText(QString::number(timeh) + ":" + QString::number(timem));

    //uwagi
    QString uwagi = "";

    if(timeh>=21 || timeh<+5)
        uwagi.append("Dron będzie latał po zmierzchu, wymagane dodatkowe oświetlenie!\n");
    if(currentBatteryTime<=30)
        uwagi.append("Akumalatory o tej pojemności potrzebują 3 minut na przygotowanie do pracy!");

    ui->info->setText(uwagi);
}


void MainWindow::on_bspModel_currentIndexChanged(int index)
{
    ui->typeofAcumulator->clear();

    switch(index)
    {
        case 0:
        {
            ui->typeofAcumulator->addItem("3500 mAh");
            ui->typeofAcumulator->addItem("4500 mAh");
            break;
        }
        case 1:
        {
            ui->typeofAcumulator->addItem("3000 mAh");
            ui->typeofAcumulator->addItem("3500 mAh");
            break;
        }
    }
}


void MainWindow::on_pushButton_3_clicked() //jakies gowno
{
    ui->progressBar->setVisible(true);
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distTemat(0, 5);
    std::uniform_int_distribution<int> distMiejsce(0, 5);
    ui->progressBar->setValue(37);
    QString tematy[] = {"portret","zabudowania","flora","fauna","transport","woda"},
            miejsca[] = {"zabytek","nowoczesne miasto","wieś","morze","las","góry"};
    QString temat = tematy[distTemat(gen)], miejsce = miejsca[distMiejsce(gen)];
    QThread::msleep(375);
    ui->progressBar->setValue(65);

    for(int i=66;i<=100;i++)
    {
        QThread::msleep(20);
        ui->progressBar->setValue(i);
    }
    ui->progressBar->setValue(100);
    ui->progressBar->setVisible(false);
    ui->miejsce->setText(miejsce);
    ui->temat->setText(temat);

}


void MainWindow::on_pushButton_2_clicked()
{
    int iloscZdjec = ui->iloscZdjec->text().toInt(),formatZdjecia,formaty,dlugoscFilmow = ui->filmyMinuty->value(),formatFilmy;
    if(ui->RAW)
        formaty = 2;
    else formaty = 1;

    switch(ui->formatZdjecia->currentIndex())
    {
        case 0:
        {
            formatZdjecia = 30;
            break;
        }
        case 1:
        {
            formatZdjecia = 50;
            break;
        }
        case 2:
        {
            formatZdjecia = 60;
            break;
        }
        case 3:
        {
            formatZdjecia = 80;
            break;
        }
    }

    switch(ui->formatfilmy->currentIndex())
    {
        case 0:
        {
            formatFilmy = 30;
            break;
        }
        case 1:
        {
            formatFilmy = 50;
            break;
        }
        case 2:
        {
            formatFilmy = 60;
            break;
        }
        case 3:
        {
            formatFilmy = 80;
            break;
        }
    }

    int wynik = (iloscZdjec * formatZdjecia * formaty + dlugoscFilmow * formatFilmy)/1024;
    qDebug()<<"wynik: "<<wynik;
    QString outputInfo;

    if(wynik<ui->horizontalSlider->value())
        outputInfo = "Twoja karta pomieści wszystkie zaplanowane pliki, ich wartość to: ";
    else
        outputInfo = "Twoja nie karta pomieści wszystkich zaplanowanych plików, ich wartość to: ";

    outputInfo.append(QString::number(wynik));
    outputInfo.append(" GB");

    if(wynik<ui->horizontalSlider->value())
        QMessageBox::information(this,"Information",outputInfo);
    else
        QMessageBox::warning(this,"Warning",outputInfo);


}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    ui->sliderValue->setText(QString::number(ui->horizontalSlider->value()));
}


void MainWindow::on_pojemnosc_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
    {
        ui->horizontalSlider->setRange(0,32);
        break;
    }
    case 1:
    {
        ui->horizontalSlider->setRange(0,64);
        break;
    }
    case 2:
    {
        ui->horizontalSlider->setRange(0,128);
        break;
    }
    case 3:
    {
        ui->horizontalSlider->setRange(0,256);
        break;
    }
    }

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString parametry[5], path;
    qDebug()<<"funkcja dziala";

    switch(index)
    {
    case 0:
        path = ":/assets/MavicAir2.txt";
        break;
    case 1:
        path = ":/assets/MavicAir2.txt";
        break;
    }
    qDebug()<<"path:"<<path;

    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<< "plik otwarty";
        QTextStream pipeline(&file);
        for (int i = 0; i < 5; ++i)
        {
            if (!pipeline.atEnd())
            {
                parametry[i] = pipeline.readLine();
                qDebug()<<parametry[i];
            }
            else
                break;
        }
        file.close();
    }

    for(int i=-1;i<=3;i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(parametry[i+1]);
        ui->tableWidget->setItem(i,1,item);
    }

}

