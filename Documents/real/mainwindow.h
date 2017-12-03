#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
#include "globals.h"
#include <vector>
#include <QSlider>
#include <QScrollBar>
#include <QVBoxLayout>
#include "calc.h" //included Calc class here

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots: //find
    void useSchemaA();
    void useSchemaB();
    void calculate();

private:
    Ui::MainWindow *ui;
    Calc* m_calc;
    int m_hw[HW_NUM];
    int m_mt[2];
    int m_final;
};

#endif // MAINWINDOW_H
