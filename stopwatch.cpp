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
    stop();
    lastLapTime = 0;
}

bool Stopwatch::isRunning() const {
    return running;
}

qint64 Stopwatch::elapsed() const {
    return timer.elapsed();
}

qint64 Stopwatch::lapTime() {
    qint64 currentTime = timer.elapsed();
    qint64 lap = currentTime - lastLapTime;
    lastLapTime = currentTime;
    return lap;
}
