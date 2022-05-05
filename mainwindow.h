#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
private:
    void move(QListWidget*, QListWidget*);
    void randomGeneration(QListWidget*);
private slots:
    void on_pbToRight_clicked();
    void on_pbToLeft_clicked();
    void on_pbLeftSort_clicked();
    void on_pbRightSort_clicked();
};
#endif // MAINWINDOW_H
