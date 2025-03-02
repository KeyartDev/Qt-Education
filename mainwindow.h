#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "passwordvalidator.h"

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


private slots:
    void on_add_clicked();

    void on_remove_clicked();

    void on_removeAll_clicked();

    void on_input_returnPressed();

private:
    Ui::MainWindow *ui;

    PasswordValidator* validator;
    QListWidgetItem* lwi;
    QString inputData;
    QStringListModel model;
    QItemSelectionModel selection = QItemSelectionModel(&model);
    QStandardItemModel model2 = QStandardItemModel(5, 3);
};
#endif // MAINWINDOW_H
