#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication> //for app to function properly
#include <string>
#include <QCheckBox>
#include <Qt>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{

   ui->setupUi(this);

   //connect slider with box:
   connect (ui->hw1_slider, SIGNAL(valueChanged(int)), ui->hw1_box, SLOT(setValue(int)) );
   connect (ui->hw2_slider, SIGNAL(valueChanged(int)), ui->hw2_box, SLOT(setValue(int)) );
   connect (ui->hw3_slider, SIGNAL(valueChanged(int)), ui->hw3_box, SLOT(setValue(int)) );
   connect (ui->hw4_slider, SIGNAL(valueChanged(int)), ui->hw4_box, SLOT(setValue(int)) );
   connect (ui->hw5_slider, SIGNAL(valueChanged(int)), ui->hw5_box, SLOT(setValue(int)) );
   connect (ui->hw6_slider, SIGNAL(valueChanged(int)), ui->hw6_box, SLOT(setValue(int)) );
   connect (ui->hw7_slider, SIGNAL(valueChanged(int)), ui->hw7_box, SLOT(setValue(int)) );
   connect (ui->hw8_slider, SIGNAL(valueChanged(int)), ui->hw8_box, SLOT(setValue(int)) );
   connect (ui->mt1_slider, SIGNAL(valueChanged(int)), ui->mt1_box, SLOT(setValue(int)) );
   connect (ui->mt2_slider, SIGNAL(valueChanged(int)), ui->mt2_box, SLOT(setValue(int)) );
   connect (ui->final_slider, SIGNAL(valueChanged(int)), ui->final_box, SLOT(setValue(int)) );


   //the other way around:
   connect (ui->hw1_box, SIGNAL(valueChanged(int)), ui->hw1_slider, SLOT(setValue(int)) );
   connect (ui->hw2_box, SIGNAL(valueChanged(int)), ui->hw2_slider, SLOT(setValue(int)) );
   connect (ui->hw3_box, SIGNAL(valueChanged(int)), ui->hw3_slider, SLOT(setValue(int)) );
   connect (ui->hw4_box, SIGNAL(valueChanged(int)), ui->hw4_slider, SLOT(setValue(int)) );
   connect (ui->hw5_box, SIGNAL(valueChanged(int)), ui->hw5_slider, SLOT(setValue(int)) );
   connect (ui->hw6_box, SIGNAL(valueChanged(int)), ui->hw6_slider, SLOT(setValue(int)) );
   connect (ui->hw7_box, SIGNAL(valueChanged(int)), ui->hw7_slider, SLOT(setValue(int)) );
   connect (ui->hw8_box, SIGNAL(valueChanged(int)), ui->hw8_slider, SLOT(setValue(int)) );


   connect (ui->schemaA, SIGNAL(clicked(bool)), this, SLOT(useSchemaA()) );
   connect (ui->schemaB, SIGNAL(clicked(bool)), this, SLOT(useSchemaB()) );

   connect(ui->calc_b, SIGNAL(released()), this, SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::calculate()
{
    m_hw [0] = ui->hw1_box->value();
    m_hw [1] = ui->hw2_box->value();
    m_hw [2] = ui->hw3_box->value();
    m_hw [3] = ui->hw4_box->value();
    m_hw [4] = ui->hw5_box->value();
    m_hw [5] = ui->hw6_box->value();
    m_hw [6] = ui->hw7_box->value();
    m_hw [7] = ui->hw8_box->value();

    m_mt [0] = ui->mt1_box->value();
    m_mt [1] = ui->mt2_box->value();
    m_final = ui->final_box->value();

    if (ui->course_box->currentIndex() == 1) //PIC10B
    {
        double bscore = m_calc->calculatePIC10B(m_hw, m_mt, m_final);
        ui->score_label->setText(QString::number(bscore));

    }
    else //PIC 10C
    {
        double score = m_calc->calcuateScore(m_hw, m_mt, m_final);
        ui->score_label->setText(QString::number(score));
    }


}

void MainWindow::useSchemaA()
{
    ui->schemaB->setCheckState(Qt::Unchecked);
    m_calc->setSchema(SCHEMA_A);
}

void MainWindow::useSchemaB()
{
    ui->schemaA->setCheckState(Qt::Unchecked);
    m_calc->setSchema(SCHEMA_B);
}
