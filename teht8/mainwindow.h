#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void timeout();
    void updateProgressBar();
    void setGameInfoText(QString text, short player);
    void switchPlayer();
    void startGame();
    void stopGame();
    void setTime120();
    void setTime300();

private:
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;

    QProgressBar *player1Bar;
    QProgressBar *player2Bar;
    QPushButton *switchButton1;
    QPushButton *switchButton2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *time120Button;
    QPushButton *time300Button;
    QLabel *infoLabel;
};
#endif // MAINWINDOW_H
