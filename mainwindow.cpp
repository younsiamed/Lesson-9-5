#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), stopwatch(new Stopwatch(this)) {
    ui->setupUi(this);

    connect(ui->startStopButton, &QPushButton::clicked, this, &MainWindow::onStartStopClicked);
    connect(ui->lapButton, &QPushButton::clicked, this, &MainWindow::onLapClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTimeDisplay);

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

void MainWindow::onLapClicked() {
    ++lapCounter;
    qint64 lapTime = stopwatch->lapTime();
    ui->lapsBrowser->append(QString("Круг %1, время: %2 сек").arg(lapCounter).arg(lapTime / 1000.0, 0, 'f', 1));
}

void MainWindow::onResetClicked() {
    lapCounter = 0;                      // Сброс счётчика кругов
    ui->lapsBrowser->clear();            // Очистка текстового браузера
    stopwatch->restart();                // Перезапуск таймера для начала с 0
    ui->timeLabel->setText("0:00.0");    // Установка метки на начальное значение
}

void MainWindow::updateTimeDisplay(qint64 milliseconds) {
    qint64 seconds = milliseconds / 1000;
    qint64 minutes = seconds / 60;
    seconds %= 60;
    qint64 tenths = (milliseconds % 1000) / 100;

    ui->timeLabel->setText(QString("%1:%2.%3")
                               .arg(minutes)
                               .arg(seconds, 2, 10, QChar('0'))
                               .arg(tenths));
}
