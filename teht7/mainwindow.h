#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void CountClickedHandler();
    void ResetClickedHandler();

    void NumberClickedHandler();
    void OperatorClickedHandler();
    void EnterClickedHandler();
    void ClearClickedHandler();

private:
    QLineEdit *counterDisplay;
    int counterValue;

    QString number1, number2;
    QLineEdit *num1Input;
    QLineEdit *num2Input;
    QLineEdit *resultDisplay;
    int state;
    int operand;

    void setupCounter(QVBoxLayout *layout);
    void setupCalculator(QVBoxLayout *layout);
};

#endif
