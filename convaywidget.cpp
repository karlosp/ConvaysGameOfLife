#include "convaywidget.h"
#include <algorithm>
#include <chrono>
#include <qDebug>
#include <convay.hpp>
#include <iostream>

#include <convay.hpp>

ConvayWidget::ConvayWidget(QWidget *parent)
    : QWidget(parent)
{
  setCrossSize(191);

  board_ = {{1,0}, {2,1}, {2,2},{1,2},{0,2}};

  timer.setInterval(50);
  connect(&timer, &QTimer::timeout, [this]() {
    board_ = convay::advance(board_);
    repaint();
  });
}

void ConvayWidget::advance() {
  board_ = convay::advance(board_);

  std::cout << board_ << std::endl;

  repaint();
}

void ConvayWidget::toggleTimer(bool value) {
  if (value) {
    timer.start();
  } else {
    timer.stop();
  }
}

void ConvayWidget::setXoffset(int value) {
  x_offset_ = value;
  qDebug() << "x_offset_: " << x_offset_;
  repaint();
}

void ConvayWidget::setYoffset(int value) {
  y_offset_ = value;
  qDebug() << "y_offset_: " << y_offset_;
  repaint();
}

void ConvayWidget::setScaleFactor(int value) {
  scale_ = value / 200.0;
  qDebug() << "scale: " << scale_;
  repaint();
}

void ConvayWidget::setCrossSize(int size) {
    board_ = convay::crossXxX(size);
}

void ConvayWidget::setAnimationSpeed(int ms) { timer.setInterval(ms); }

void operator <<(QPainter &painter, convay::Board const& board){
    for (auto const &cell : board) {
      painter.fillRect(QRectF(cell.first * 10, cell.second * 10, 10, 10),
                       QBrush(Qt::black));
    }
}

void ConvayWidget::paintEvent(QPaintEvent *event) {

  if (board_.empty())
    return;

  QPainter painter(this);
  painter.translate(x_offset_, y_offset_);
  painter.scale(scale_, scale_);
  painter << board_;
}


