#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), player1Time(120), player2Time(120), gameTime(120), currentPlayer(1) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *playersLayout = new QHBoxLayout();
    QHBoxLayout *midLayout = new QHBoxLayout();
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QVBoxLayout *player1Layout = new QVBoxLayout();
    QVBoxLayout *player2Layout = new QVBoxLayout();

    startButton = new QPushButton("START GAME", this);
    stopButton = new QPushButton("STOP GAME", this);
    switchButton1 = new QPushButton("Swich player", this);
    switchButton2 = new QPushButton("Swich player", this);
    time120Button = new QPushButton("120 sec", this);
    time300Button = new QPushButton("5 min", this);
    player1Bar = new QProgressBar(this);
    player2Bar = new QProgressBar(this);
    infoLabel = new QLabel("Game not started", this);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    pQTimer = new QTimer(this);

    player1Bar->setRange(0, gameTime);
    player2Bar->setRange(0, gameTime);
    player1Bar->setValue(gameTime);
    player2Bar->setValue(gameTime);

    player1Layout->addWidget(player1Bar);
    player1Layout->addWidget(switchButton1);

    player2Layout->addWidget(player2Bar);
    player2Layout->addWidget(switchButton2);

    playersLayout->addLayout(player1Layout);
    playersLayout->addLayout(player2Layout);

    midLayout->addWidget(time120Button);
    midLayout->addWidget(time300Button);

    bottomLayout->addWidget(startButton);
    bottomLayout->addWidget(stopButton);

    mainLayout->addLayout(playersLayout);
    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(midLayout);
    mainLayout->addLayout(bottomLayout);

    setCentralWidget(centralWidget);

    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);
    connect(switchButton1, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(switchButton2, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(time120Button, &QPushButton::clicked, this, &MainWindow::setTime120);
    connect(time300Button, &QPushButton::clicked, this, &MainWindow::setTime300);
}

MainWindow::~MainWindow() {}

void MainWindow::timeout() {
    if (currentPlayer == 1) {
        if (player1Time > 0) player1Time--;
    } else {
        if (player2Time > 0) player2Time--;
    }

    updateProgressBar();

    if (player1Time == 0 || player2Time == 0) {
        setGameInfoText(player1Time == 0 ? "Player 2 Wins!" : "Player 1 Wins!", currentPlayer);
        stopGame();
        return;
    }
}


void MainWindow::updateProgressBar() {
    player1Bar->setValue(player1Time);
    player2Bar->setValue(player2Time);
}

void MainWindow::setGameInfoText(QString text, short player) {
    infoLabel->setText(text);
}

void MainWindow::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    setGameInfoText("Player " + QString::number(currentPlayer) + " Turn", currentPlayer);
}

void MainWindow::startGame() {
    pQTimer->start(1000);
    setGameInfoText("Game ongoing", currentPlayer);

    startButton->setEnabled(false);
    stopButton->setEnabled(true);
    time120Button->setEnabled(false);
    time300Button->setEnabled(false);
}

void MainWindow::stopGame() {
    pQTimer->stop();
    setGameInfoText("Game Stopped", currentPlayer);

    startButton->setEnabled(true);
    stopButton->setEnabled(false);
    time120Button->setEnabled(true);
    time300Button->setEnabled(true);
}

void MainWindow::setTime120() {
    gameTime = 120;
    player1Time = gameTime;
    player2Time = gameTime;

    player1Bar->setRange(0, gameTime);
    player2Bar->setRange(0, gameTime);
    player1Bar->setValue(player1Time);
    player2Bar->setValue(player2Time);

    setGameInfoText("Time set to 120 sec", currentPlayer);
}

void MainWindow::setTime300() {
    gameTime = 300;
    player1Time = gameTime;
    player2Time = gameTime;

    player1Bar->setRange(0, gameTime);
    player2Bar->setRange(0, gameTime);
    player1Bar->setValue(player1Time);
    player2Bar->setValue(player2Time);

    setGameInfoText("Time set to 5 min", currentPlayer);
}
