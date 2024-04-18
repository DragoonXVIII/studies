
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
    void on_oblicz_clicked();

    void on_pokazautora_ChcBx_stateChanged(int arg1);

    void on_calendarWidget_selectionChanged();

    void on_pushButton_clicked();

    void on_horizontalSlider_actionTriggered(int action);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();



    void on_actionKopiuj_triggered();

    void on_actionWytnij_triggered();

    void on_actionWklej_triggered();

    void on_actionk1_triggered();

    void on_actionk2_triggered();

private:
    Ui::MainWindow *ui;
    QString schowek;
};

#endif // MAINWINDOW_H
