#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include "./ui_mainwindow.h"
#include "QPushButton"
#include "difficultyselector.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gridLayout(new QGridLayout(this))
{
    ui->setupUi(this);

    // Initialize grid and set it on central widget
    if (ui->centralwidget->layout()) {
        delete ui->centralwidget->layout(); // Remove any existing layout
    }
    ui->centralwidget->setLayout(gridLayout);

    // Initialize status label
    statusLabel = new QLabel("Welcome to Minesweeper!", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(statusLabel, 0, 0, 1, 10);

    // Initialize the reset button
    resetButton = new QPushButton("New Game", this);
    gridLayout->addWidget(resetButton, 1, 0, 1, 10);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::showDifficultySelector);

    // Show difficulty selection dialog initially
    showDifficultySelector();
}

void MainWindow::showDifficultySelector()
{
    DifficultySelector *difficultySelector = new DifficultySelector(this);

    connect(difficultySelector,
            &DifficultySelector::difficultyConfirmed,
            this,
            &MainWindow::setupGrid);

    difficultySelector->exec();
}

void MainWindow::setupGrid(int rows, int columns)
{
    // Clear existing items on GridLayout
    QLayoutItem *child;
    while ((child = gridLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Populate grid with buttons for each cell
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(30, 30);
            gridLayout->addWidget(button, row, col);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
