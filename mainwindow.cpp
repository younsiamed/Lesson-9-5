#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), stopwatch(new Stopwatch(this)) {
    ui->setupUi(this);

    // Подключение кнопок к слотам
    connect(ui->startStopButton, &QPushButton::clicked, this, &MainWindow::onStartStopClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(ui->lapButton, &QPushButton::clicked, this, &MainWindow::onLapClicked);
    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTime);

    ui->lapButton->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartStopClicked() {
    if (stopwatch->isRunning()) {
        stopwatch->stop();
        ui->startStopButton->setText("Старт");
        ui->lapButton->setEnabled(false);
    } else {
        stopwatch->start();
        ui->startStopButton->setText("Стоп");
        ui->lapButton->setEnabled(true);
    }
}

void MainWindow::onResetClicked() {
    stopwatch->reset();
    ui->lapsBrowser->clear();
    ui->startStopButton->setText("Старт");
    ui->lapButton->setEnabled(false);
}

void MainWindow::onLapClicked() {
    QString lapText = QString("Круг %1, время: %2")
                          .arg(stopwatch->getLapCount())
                          .arg(stopwatch->getLastLapTime());
    ui->lapsBrowser->append(lapText);
}

void MainWindow::updateTime(const QString &time) {
    ui->timeLabel->setText(time);
}
