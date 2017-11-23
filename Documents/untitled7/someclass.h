#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QMainWindow>

namespace Ui {
class SomeClass;
}

class SomeClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit SomeClass(QWidget *parent = 0);
    ~SomeClass();

private:
    Ui::SomeClass *ui;
};

#endif // SOMECLASS_H
