#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

// Перечисления операций
enum Operation
{
    plus = 100,
    minus,
    multi,
    del,
    clear,
    add
};

// Перечислений клавиш
enum Button
{
    numberOne = 1,
    numberTwo,
    numberThree,
    numberFour,
    numberFive,
    numberSix,
    numberSeven,
    numberEight,
    numberNine,
    numberZero,
    operationClear,
    operationPlus,
    operationMinus,
    operationMulti,
    operationDel
};

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    // Вычисление
    void methodCalculate(int argument, Operation operation);

private slots:
    // Нажатие клавиш
    void keystrokes();

signals:
    void calculate();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
