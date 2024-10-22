#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "catalog.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QListView>
#include <QStandardItemModel>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void loadCatalog();


    private:
        Ui::MainWindow *ui;
        Catalog catalog;

    private slots:
        void on_addButton_released();
        void on_deleteButton_released();
        void on_countButton_released();


        void on_sortY_released();
        void on_sortA_released();
};
#endif // MAINWINDOW_H
