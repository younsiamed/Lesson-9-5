#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent), elapsedTime(0), lastLapTime(0), lapCount(0), running(false) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        elapsedTime += 100; // Увеличиваем время на 0.1 секунды
        emit timeUpdated(getTime());
    });
}

void Stopwatch::start() {
    if (!running) {
        timer->start(100);
        running = true;
    }
}

void Stopwatch::stop() {
    if (running) {
        timer->stop();
        running = false;
    }
}

void Stopwatch::reset() {
    stop();
    elapsedTime = 0;
    lastLapTime = 0;
    lapCount = 0;
    emit timeUpdated(getTime());
}

void Stopwatch::recordLap() {
    if (running) {
        ++lapCount;
        qint64 lapTime = elapsedTime - lastLapTime;
        lastLapTime = elapsedTime;
    }
}

QString Stopwatch::getTime() const {
    int milliseconds = elapsedTime % 1000;
    int seconds = (elapsedTime / 1000) % 60;
    int minutes = (elapsedTime / 60000) % 60;
    return QString("%1:%2.%3")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'))
        .arg(milliseconds / 100, 1, 10, QChar('0'));
}

QString Stopwatch::getLastLapTime() const {
    int lapMilliseconds = (elapsedTime - lastLapTime) % 1000;
    int lapSeconds = ((elapsedTime - lastLapTime) / 1000) % 60;
    int lapMinutes = ((elapsedTime - lastLapTime) / 60000) % 60;
    return QString("%1:%2.%3")
        .arg(lapMinutes, 2, 10, QChar('0'))
        .arg(lapSeconds, 2, 10, QChar('0'))
        .arg(lapMilliseconds / 100, 1, 10, QChar('0'));
}
