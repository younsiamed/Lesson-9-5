#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartStopClicked();
    void onResetClicked();
    void onLapClicked();
    void updateTime(const QString &time);

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
};

#endif // MAINWINDOW_H
