#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSplitter"
#include "QTextEdit"
#include "passwordvalidator.h"
#include "QListWidgetItem"
#include "QList"
#include "QMessageBox"

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

private:
    Ui::MainWindow *ui;

    PasswordValidator* validator;
    QListWidgetItem* lwi;
    QString inputData;
};
#endif // MAINWINDOW_H
