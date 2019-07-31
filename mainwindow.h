#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "binarysearchtree.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_4_clicked();//for add

    void on_pushButton_clicked();//for search

    void on_pushButton_2_clicked();//for listing students by family name

    void on_pushButton_3_clicked();//for listing students by average


private:
    Ui::MainWindow *ui;
    BinarySearchTree BST;
    BinarySearchTree BST2;
    QString tendency;
    QMessageBox messageBox;
    int counter=1;
};

#endif // MAINWINDOW_H
