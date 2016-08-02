#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QMessageBox>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::methodCalculate(int argument, Operation operation)
{
    // Отслеживание предыдущей операции
    static QString operationSave = "null";

    // Отслеживание результата
    static int result(0);

    switch (operation)
    {
        case add:
        if (operationSave == "plus")
        {
            result += argument;
            operationSave = "null";
            break;
        }

        else if (operationSave == "minus")
        {
            result -= argument;
            operationSave = "null";
            break;
        }

        else if (operationSave == "multi")
        {
            result *= argument;
            operationSave = "null";
            break;
        }

        else if (operationSave == "del")
        {
            (argument == 0) ? (QMessageBox::information(0, "Предупреждение!!!", "<h1>Деление на ноль!!!</h1>")) : (result /= argument);
            operationSave = "null";
            break;
        }

        if (result == 0)
            result += argument;

        else
        {
            result *= 10;
            result += argument;
        }

        break;

        case clear:
        result = 0;
        operationSave = "null";
        break;

        case plus:
        operationSave = "plus";
        break;

        case minus:
        operationSave = "minus";
        break;

        case multi:
        operationSave = "multi";
        break;

        case del:
        operationSave = "del";
        break;
    }

    ui->lcdDisplay->display(result);
}

void MainWidget::keystrokes()
{
    // Номер клавишы
    Button button = operationClear;

    if (sender()->objectName() == "numberOne")
        button = numberOne;
    else if (sender()->objectName() == "numberTwo")
        button = numberTwo;
    else if (sender()->objectName() == "numberThree")
        button = numberThree;
    else if (sender()->objectName() == "numberFour")
        button = numberFour;
    else if (sender()->objectName() == "numberFive")
        button = numberFive;
    else if (sender()->objectName() == "numberSix")
        button = numberSix;
    else if (sender()->objectName() == "numberSeven")
        button = numberSeven;
    else if (sender()->objectName() == "numberEight")
        button = numberEight;
    else if (sender()->objectName() == "numberNine")
        button = numberNine;
    else if (sender()->objectName() == "numberZero")
        button = numberZero;
    else if (sender()->objectName() == "operationClear")
        button = operationClear;
    else if (sender()->objectName() == "operationPlus")
        button = operationPlus;
    else if (sender()->objectName() == "operationMinus")
        button = operationMinus;
    else if (sender()->objectName() == "operationMulti")
        button = operationMulti;
    else if (sender()->objectName() == "operationDel")
        button = operationDel;

    switch (button)
    {
        case numberOne:
        this->methodCalculate(1, add);
        break;

        case numberTwo:
        this->methodCalculate(2, add);
        break;

        case numberThree:
        this->methodCalculate(3, add);
        break;

        case numberFour:
        this->methodCalculate(4, add);
        break;

        case numberFive:
        this->methodCalculate(5, add);
        break;

        case numberSix:
        this->methodCalculate(6, add);
        break;

        case numberSeven:
        this->methodCalculate(7, add);
        break;

        case numberEight:
        this->methodCalculate(8, add);
        break;

        case numberNine:
        this->methodCalculate(9, add);
        break;

        case numberZero:
        this->methodCalculate(0, add);
        break;

        case operationClear:
        this->methodCalculate(0, clear);
        break;

        case operationPlus:
        this->methodCalculate(0, plus);
        break;

        case operationMinus:
        this->methodCalculate(0, minus);
        break;

        case operationMulti:
        this->methodCalculate(0, multi);
        break;

        case operationDel:
        this->methodCalculate(0, del);
        break;
    }
}
