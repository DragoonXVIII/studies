#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "catalog.h"
#include "countrytable.h"

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
        void loadTable();

    private:
        Ui::MainWindow *ui;
        Catalog catalog;
        CountryTable table;

    private slots:
        void on_addButton_released();
        void on_deleteButton_released();
        void on_countButton_released();
        void on_sortY_released();
        void on_sortA_released();

        void on_addCountryButton_released();
        void on_deleteCountryButton_released();
        void on_showPeopleNumbers_released();
        void on_sortIButton_released();
        void on_sortDButton_released();
        void on_deleteCountryButton_2_released();
};
#endif // MAINWINDOW_H
