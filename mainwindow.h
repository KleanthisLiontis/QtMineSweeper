#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include "difficultySelector.h"

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
    QLabel *statusLabel;                    //To display game status messages
    QPushButton *resetButton;               //Button to reset the game
    QComboBox *difficultyComboBox;          //Combo box for difficulty settings
    DifficultySelector *difficultySelector; //Pointer to difficulty selector
    bool isInitialized = false;             //Variable to check for resetting the game

    //function to setup dynamic grid based on difficulty
    void setupGrid(int rows, int columns);
    void resetGame();

private slots:
    void updateGridBasedOnDifficulty(const QString &difficulty);
};
#endif // MAINWINDOW_H
