#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <convaywidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_toggled(bool checked);

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_sliderMoved(int position);

    void on_verticalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_rangeChanged(int min, int max);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_pushButton_3_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
