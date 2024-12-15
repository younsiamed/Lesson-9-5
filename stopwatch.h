#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void recordLap();
    QString getTime() const;         // Возвращает строку времени
    QString getLastLapTime() const; // Возвращает строку последнего круга
    int getLapCount() const { return lapCount; }
    bool isRunning() const { return running; }

signals:
    void timeUpdated(const QString &time);

private:
    QTimer *timer;
    qint64 elapsedTime;      // Общее время в миллисекундах
    qint64 lastLapTime;      // Время предыдущего круга
    int lapCount;            // Счётчик кругов
    bool running;            // Флаг, указывающий на работу секундомера
};

#endif // STOPWATCH_H
