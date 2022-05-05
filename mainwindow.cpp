#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lwLeft->setSelectionMode(QAbstractItemView::ContiguousSelection);
    ui->lwRight->setSelectionMode(QAbstractItemView::ContiguousSelection);

    ui->centralwidget->setLayout(ui->glInterface);

    randomGeneration(ui->lwLeft);
    randomGeneration(ui->lwRight);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::randomGeneration(QListWidget* lw) {
    QRandomGenerator *rgRows(QRandomGenerator::global());
    QRandomGenerator *rgNum(QRandomGenerator::global());
    QRandomGenerator *rgLetter(QRandomGenerator::global());
    QString str;
    int rows, num, letter;
    rows = rgRows->bounded(0,20);
    for (int i = 0; i < rows; i++) {
        num = rgNum->bounded(1, 20);
        str = "";
        for (int k = 0; k < num; k++) {
            letter = rgLetter->bounded(97,122);
            str += (char)letter;
        }
        lw->addItem(str);
    }
}
void MainWindow::on_pbToRight_clicked()
{
    move(ui->lwLeft, ui->lwRight);
}

void MainWindow::move(QListWidget *lwFrom, QListWidget *lwTo) {
    QList<QListWidgetItem*> lItems = lwFrom->selectedItems();
    if (lItems.empty()) {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setText("Select an item");
        msg.exec();
    }
    foreach(QListWidgetItem* lwiItem, lItems){
        lwTo->addItem(lwiItem->text());
        lwFrom->removeItemWidget(lwiItem);
        delete lwiItem;
    }
}
void MainWindow::on_pbToLeft_clicked()
{
    move(ui->lwRight, ui->lwLeft);
}

void MainWindow::on_pbLeftSort_clicked()
{
    ui->lwLeft->sortItems(Qt::AscendingOrder);
}


void MainWindow::on_pbRightSort_clicked()
{
    ui->lwRight->sortItems(Qt::DescendingOrder);
}
