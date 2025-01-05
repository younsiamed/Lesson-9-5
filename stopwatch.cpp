#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent) {
    connect(&updateTimer, &QTimer::timeout, this, [this]() {
        if (running) {
            emit timeUpdated(timer.elapsed());
        }
    });
}

void Stopwatch::start() {
    if (!running) {
        running = true;
        timer.start();
        lastLapTime = 0;
        updateTimer.start(100);
    }
}

void Stopwatch::stop() {
    if (running) {
        running = false;
        updateTimer.stop();
    }
}

void Stopwatch::reset() {
    timer.invalidate(); // Invalidate the timer
    lastLapTime = 0;
}

void Stopwatch::resetLapTime() {
    lastLapTime = timer.elapsed(); // Сброс времени круга на текущее прошедшее время
}

void Stopwatch::restart() {
    timer.start();  // Перезапуск таймера
    lastLapTime = 0;
}

bool Stopwatch::isRunning() const {
    return running;
}

qint64 Stopwatch::elapsed() const {
    return timer.isValid() ? timer.elapsed() : 0;
}

qint64 Stopwatch::lapTime() {
    qint64 currentTime = elapsed();
    qint64 lap = currentTime - lastLapTime;
    lastLapTime = currentTime;
    return lap;
}
