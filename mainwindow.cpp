#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include "./ui_mainwindow.h"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gridLayout(new QGridLayout()) // For game layout
{
    ui->setupUi(this);

    // Initialize grid and add it to central widget
    gridLayout = new QGridLayout(this); // Make gridLayout a member variable in the header file
    ui->centralwidget->setLayout(gridLayout);

    //Initialize status label
    statusLabel = new QLabel("Welcome to Minesweeper!", this);
    statusLabel->setAlignment(Qt::AlignCenter);      // Center text
    gridLayout->addWidget(statusLabel, 0, 0, 1, 10); // Span across the gridLayout

    /// Initialize the reset button
    resetButton = new QPushButton("New Game", this);
    gridLayout->addWidget(resetButton, 1, 0, 1, 10); // Place below the status label
    //Connect the reset button signal to a slot(for later);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetGame);

    // Initialize the difficulty combo box
    difficultyComboBox = new QComboBox(this);
    difficultyComboBox->addItem("Easy");
    difficultyComboBox->addItem("Medium");
    difficultyComboBox->addItem("Hard");
    gridLayout->addWidget(difficultyComboBox, 2, 0, 1, 10); // Place below the reset button
    connect(difficultyComboBox,
            &QComboBox::currentTextChanged,
            this,
            &MainWindow::updateGridBasedOnDifficulty);

    // Setup initial grid with medium difficulty
    setupGrid(10, 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function do dynamically initialize the grid
void MainWindow::setupGrid(int rows, int columns)
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

// Function to reset the game
void MainWindow::resetGame()
{
    if (!isInitialized) {
        setupGrid(10, 10); // Default to medium grid if not initialized
        isInitialized = true;
    } else {
        QString currentDifficulty = difficultyComboBox->currentText();
        updateGridBasedOnDifficulty(currentDifficulty);
    }
}

// Function to update grid size based on selected difficulty
void MainWindow::updateGridBasedOnDifficulty(const QString &difficulty)
{
    if (difficulty == "Easy") {
        setupGrid(8, 8); // Example grid size for easy
    } else if (difficulty == "Medium") {
        setupGrid(10, 10); // Example grid size for medium
    } else if (difficulty == "Hard") {
        setupGrid(16, 16); // Example grid size for hard
    }
    isInitialized = true; // Mark as initialized once difficulty is set
}
