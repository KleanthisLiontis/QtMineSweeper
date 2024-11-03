#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    //function to setup dynamic grid based on difficulty
    void setupGrid(int rows, int columns);

private:
    Ui::MainWindow *ui;
    QGridLayout *gridLayout;
    QLabel *statusLabel;      // to display game status messages
    QPushButton *resetButton; //Button to reset the game
};
#endif // MAINWINDOW_H
