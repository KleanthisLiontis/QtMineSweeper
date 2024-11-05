#ifndef DIFFICULTYSELECTOR_H
#define DIFFICULTYSELECTOR_H

#include <QComboBox>
#include <QDialog>
#include <QPushButton>

class DifficultySelector : public QDialog
{
    Q_OBJECT
public:
    explicit DifficultySelector(QWidget *parent = nullptr);

    int getRows() const;
    int getColumns() const;

signals:
    void difficultyConfirmed(int rows, int columns); // Signal for confirming difficulty

private:
    QComboBox *difficultyComboBox;
    QPushButton *okButton; // OK button for confirming difficulty selection
    int rows;
    int columns;

private slots:
    void onDifficultyChanged(int index);
    void onOkButtonClicked(); // Slot for handling OK button click
};

#endif // DIFFICULTYSELECTOR_H
