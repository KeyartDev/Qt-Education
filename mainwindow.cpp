#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->list->setSelectionMode(QAbstractItemView::MultiSelection);

    model.setStringList(QStringList() << "First"
                                      << "Second"
                                      << "Third");

    ui->list_2->setModel(&model);
    ui->list_2->setSelectionModel(&selection);
    ui->tree->setModel(&model);
    ui->tree->setSelectionModel(&selection);
    ui->table->setModel(&model);
    ui->table->setSelectionModel(&selection);
    //-------------------model2-----------------------
    for (int nTopRow=0;nTopRow<5;++nTopRow)
    {
        QModelIndex index = model2.index(nTopRow, 0);
        model2.setData(index, "item"+QString::number(nTopRow+1), Qt::DisplayRole);
        model2.setData(index, "It's tooltip for element №"+QString::number(nTopRow+1), Qt::ToolTipRole);

        model2.insertRows(0, 4, index);
        model2.insertColumns(0, 3, index);
        for (int nRow=0;nRow<4;++nRow) {
            for (int nCol=0;nCol<3;++nCol) {
                QString strPos = QString("%1,%2").arg(nRow).arg(nCol);
                model2.setData(model2.index(nRow, nCol, index), strPos);
            }
        }
    }
    ui->treeIe->setModel(&model2);
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


void MainWindow::on_input_returnPressed()
{
    emit ui->add->clicked();
}

