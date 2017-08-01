#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <convay.hpp>
#include <chrono>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget, &ConvayWidget::fps, [this](int fps){
        ui->label_fps->setText(QString::number(fps));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->advance();
}

void MainWindow::on_pushButton_2_toggled(bool checked)
{
    ui->widget->toggleTimer(checked);
    ui->pushButton->setDisabled(checked);
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->widget->setXoffset(position);
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    ui->widget->setYoffset(position);
}

void MainWindow::on_horizontalSlider_2_rangeChanged(int min, int max)
{

}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->widget->setScaleFactor(position);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->setCrossSize(ui->spinBox->value());
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->widget->setAnimationSpeed(arg1);
}

template<typename TimeT = std::chrono::microseconds,
    typename ClockT=std::chrono::high_resolution_clock,
    typename DurationT=double>
class Stopwatch
{
private:
    std::chrono::time_point<ClockT> _start, _end;
public:
    Stopwatch() { start(); }
    void start() { _start = _end = ClockT::now(); }
    DurationT stop() { _end = ClockT::now(); return elapsed();}
    DurationT elapsed() {
        auto delta = std::chrono::duration_cast<TimeT>(_end-_start);
        return delta.count();
    }
};

void MainWindow::on_pushButton_4_clicked()
{
    int X_size = 500;
    int generations = 500;
    std::cout << "Starting benchmark" << std::endl;
    auto board = convay::crossXxX(X_size);

    Stopwatch<std::chrono::duration<double>> sw;
    for(auto i =0; i < generations; ++i){
        board = convay::advance(board);
    }
    sw.stop();
    std::cout << board;
    std::cout << "benchmark took " << QString("x size: %1\t generations: %2 \n").arg(X_size).arg(generations).toStdString() << sw.elapsed() << " seconds" << std::endl;


}
