
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_bspModel_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_actionTriggered(int action);

    void on_pojemnosc_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    QString currentBspModel;
    QString currentBatterryModel;
    int currentFlightMode;
    int currentBatterryAmount;
    int currentBatterryNumber;
    int currentBatteryTime;

};

#endif // MAINWINDOW_H
