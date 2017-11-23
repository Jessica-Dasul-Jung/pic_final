#include "someclass.h"
#include "ui_someclass.h"

SomeClass::SomeClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SomeClass)
{
    ui->setupUi(this);
}

SomeClass::~SomeClass()
{
    delete ui;
}
