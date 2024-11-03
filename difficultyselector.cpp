#include "difficultyselector.h"

DifficultySelector::DifficultySelector(QWidget *parent)
    : QWidget{parent}
    , difficultyComboBox(new QComboBox(this))
{
    //Add Difficulty levels to combo box
    difficultyComboBox->addItem("Easy");
    difficultyComboBox->addItem("Medium");
    difficultyComboBox->addItem("Hard");

    //Connecting combobox to slot to detect changes
    connect(difficultyComboBox,
            &QComboBox::currentIndexChanged,
            this,
            &DifficultySelector::onDifficultyChanged);
}

void DifficultySelector::onDifficultyChanged(int index)
{
    int rows, columns;
    switch (index) {
    case 0: //Easy
        rows = 8;
        columns = 8;
        break;
    case 1: //Medium
        rows = 16;
        columns = 16;
        break;
    case 2: //Hard
        rows = 24;
        columns = 24;
        break;
    }
    emit difficultyChanged(rows, columns); //Emit the signal with the new dimensions
}

int DifficultySelector::getSelectedDifficulty() const
{
    return difficultyComboBox->currentIndex();
}
