#ifndef DIFFICULTYSELECTOR_H
#define DIFFICULTYSELECTOR_H

#include <QObject>
#include <QWidget>

class DifficultySelector : public QWidget
{
    Q_OBJECT
public:
    explicit DifficultySelector(QWidget *parent = nullptr);
    int getSelectedDifficulty() const;

signals:
    void difficultyChanged(int rows, int columns); //Signal emitted when difficulty changes

private:
    QCombo *difficultyComboBox; //Combo box for selecting difficulty

private slots:
    void onDifficultyChanged(int index); //Slot for handling difficulty changes
};

#endif // DIFFICULTYSELECTOR_H
