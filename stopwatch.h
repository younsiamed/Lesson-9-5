#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QElapsedTimer>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();
    bool isRunning() const;

    qint64 elapsed() const;
    qint64 lapTime();

signals:
    void timeUpdated(qint64 milliseconds);

private:
    bool running = false;
    QElapsedTimer timer;
    QTimer updateTimer;
    qint64 lastLapTime = 0;
};

#endif // STOPWATCH_H
