#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include "difficultyselector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGridLayout *gridLayout;
    QLabel *statusLabel;
    QPushButton *resetButton;
    bool isInitialized;

    void setupGrid(int rows, int columns);
    void resetGame();

private slots:
    void updateGridBasedOnDifficulty(int rows, int columns);
};
#endif // MAINWINDOW_H
