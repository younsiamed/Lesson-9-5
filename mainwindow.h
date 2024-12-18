#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Stopwatch.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartStopClicked();
    void onLapClicked();
    void onResetClicked();

    void updateTimeDisplay(qint64 milliseconds);

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    int lapCounter = 0;
};

#endif // MAINWINDOW_H
