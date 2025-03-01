#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->list->setSelectionMode(QAbstractItemView::MultiSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_clicked()
{
    inputData = ui->input->text();
    if (!inputData.isEmpty())
    {
        lwi = new QListWidgetItem(inputData, ui->list);
        ui->input->clear();
        ui->input->setFocus(Qt::OtherFocusReason);
    } else
    {
        QMessageBox* box = new QMessageBox("Ошибка!", "Не удалось добавить элемент в список: пустое значение!", QMessageBox::Critical, QMessageBox::Ok, 0, 0, this);
        box->show();
    }

}

void MainWindow::on_remove_clicked()
{
    QList<QListWidgetItem*> list = ui->list->selectedItems();
    QListIterator<QListWidgetItem*> p(list);
    while (p.hasNext()) {
        delete p.next();
    }
}


void MainWindow::on_removeAll_clicked()
{
    ui->list->clear();
}

