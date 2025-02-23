#include "mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), counterValue(0), operand(-1), state(1) {

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    setupCounter(mainLayout);
    setupCalculator(mainLayout);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::setupCounter(QVBoxLayout *layout) {
    QHBoxLayout *counterLayout = new QHBoxLayout();
    counterDisplay = new QLineEdit("0");
    counterDisplay->setReadOnly(true);

    QPushButton *countButton = new QPushButton("Count");
    QPushButton *resetButton = new QPushButton("Reset");

    connect(countButton, &QPushButton::clicked, this, &MainWindow::CountClickedHandler);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::ResetClickedHandler);

    counterLayout->addWidget(counterDisplay);
    counterLayout->addWidget(countButton);
    counterLayout->addWidget(resetButton);

    layout->addLayout(counterLayout);
}

void MainWindow::setupCalculator(QVBoxLayout *layout) {
    QGridLayout *calcLayout = new QGridLayout();

    QLabel *label1 = new QLabel("Number 1:");
    QLabel *label2 = new QLabel("Number 2:");
    QLabel *labelResult = new QLabel("Result:");

    num1Input = new QLineEdit();
    num2Input = new QLineEdit();
    resultDisplay = new QLineEdit();
    resultDisplay->setReadOnly(true);

    calcLayout->addWidget(label1, 0, 0);
    calcLayout->addWidget(num1Input, 0, 1);
    calcLayout->addWidget(label2, 1, 0);
    calcLayout->addWidget(num2Input, 1, 1);
    calcLayout->addWidget(labelResult, 2, 0);
    calcLayout->addWidget(resultDisplay, 2, 1);

    QStringList buttons = { "7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "*", "0", "C", "=", "/" };

    int row = 3, col = 0;
    for (const auto &text : buttons) {
        QPushButton *button = new QPushButton(text);
        calcLayout->addWidget(button, row, col);

        if (text >= "0" && text <= "9") {
            connect(button, &QPushButton::clicked, this, &MainWindow::NumberClickedHandler);
        } else if (text == "C") {
            connect(button, &QPushButton::clicked, this, &MainWindow::ClearClickedHandler);
        } else if (text == "=") {
            connect(button, &QPushButton::clicked, this, &MainWindow::EnterClickedHandler);
        } else {
            connect(button, &QPushButton::clicked, this, &MainWindow::OperatorClickedHandler);
        }

        col++;
        if (col > 3) {
            col = 0;
            row++;
        }
    }

    layout->addLayout(calcLayout);
}

void MainWindow::CountClickedHandler() {
    counterValue++;
    counterDisplay->setText(QString::number(counterValue));
}

void MainWindow::ResetClickedHandler() {
    counterValue = 0;
    counterDisplay->setText("0");
}

void MainWindow::NumberClickedHandler() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString text = button->text();

    if (state == 1) {
        number1 += text;
        num1Input->setText(number1);
    } else {
        number2 += text;
        num2Input->setText(number2);
    }
}

void MainWindow::OperatorClickedHandler() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString text = button->text();
    if (text == "+") operand = 0;
    else if (text == "-") operand = 1;
    else if (text == "*") operand = 2;
    else if (text == "/") operand = 3;

    state = 2;
}

void MainWindow::ClearClickedHandler() {
    number1.clear();
    number2.clear();
    operand = -1;
    state = 1;
    num1Input->clear();
    num2Input->clear();
    resultDisplay->clear();
}

void MainWindow::EnterClickedHandler() {
    if (number1.isEmpty() || number2.isEmpty()) return;

    float num1 = number1.toFloat();
    float num2 = number2.toFloat();
    float result = 0;

    switch (operand) {
    case 0: result = num1 + num2; break;
    case 1: result = num1 - num2; break;
    case 2: result = num1 * num2; break;
    case 3:
        if (num2 != 0) result = num1 / num2;
        else result = 0;
        break;
    }

    resultDisplay->setText(QString::number(result));
    number1.clear();
    number2.clear();
    state = 1;
}
