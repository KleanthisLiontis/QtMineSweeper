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

private:
    Ui::MainWindow *ui;
    QGridLayout *gridLayout;
    QLabel *statusLabel;      // to display game status messages
    QPushButton *resetButton; //Button to reset the game
    QGridLayout *gridLayout;
    QComboBox *difficultyComboBox;          //Combo box for difficulty settings
    DifficultySelector *difficultySelector; //Pointer to difficulty selector
    //function to setup dynamic grid based on difficulty
    void setupGrid(int rows, int columns);

private slots:
    void onDifficultyChanged(); // Slot to handle difficulty change
};
#endif // MAINWINDOW_H
