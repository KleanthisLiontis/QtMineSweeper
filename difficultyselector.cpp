#include "difficultyselector.h"
#include <QVBoxLayout>

DifficultySelector::DifficultySelector(QWidget *parent)
    : QDialog(parent)
    , difficultyComboBox(new QComboBox(this))
    , okButton(new QPushButton("OK", this))
    , rows(10)
    , columns(10)
{
    // Add difficulty levels
    difficultyComboBox->addItem("Easy");
    difficultyComboBox->addItem("Medium");
    difficultyComboBox->addItem("Hard");

    connect(difficultyComboBox,
            &QComboBox::currentIndexChanged,
            this,
            &DifficultySelector::onDifficultyChanged);
    connect(okButton, &QPushButton::clicked, this, &DifficultySelector::onOkButtonClicked);

    // Set dialog layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(difficultyComboBox);
    layout->addWidget(okButton);
    setLayout(layout);

    setWindowTitle("Select Difficulty");
}

void DifficultySelector::onDifficultyChanged(int index)
{
    switch (index) {
    case 0: // Easy
        rows = 8;
        columns = 8;
        break;
    case 1: // Medium
        rows = 10;
        columns = 10;
        break;
    case 2: // Hard
        rows = 16;
        columns = 16;
        break;
    }
}

void DifficultySelector::onOkButtonClicked()
{
    emit difficultyConfirmed(rows, columns); // Emit signal with selected difficulty
    accept();                                // Close the dialog
}

int DifficultySelector::getRows() const
{
    return rows;
}
int DifficultySelector::getColumns() const
{
    return columns;
}
