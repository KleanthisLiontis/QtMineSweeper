#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize grid add it to central widget
    QGridLayout *gridLayout = new QGridLayout(this);
    ui->centralwidget->setLayout(gridLayout);

    //Setup a grid based on difficulty
    setupGrid(10, 10); //Med difficulty
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function do dynamically initialize the grid
void MainWindow::setuPGrid(int rows, int columns)
{
    //Clear existing items on GridLayout
    QLayoutItem *child;
    while ((child = gridLayout->takeAt(0) != nullprt)) {
        delete child->widget();
        delete child;
    }

    //Populate grid with button for each cell
    // Populate grid with buttons for each cell
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(30, 30); // Set a fixed size for each button
            gridLayout->addWidget(button, row, col);
        }
    }
}
