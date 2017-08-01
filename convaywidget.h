#ifndef CONVAYWIDGET_H
#define CONVAYWIDGET_H

#include <QWidget>
#include <vector>
#include <tuple>
#include <QTimer>
#include <map>
#include <QPainter>
#include <set>
#include <memory>

namespace convay {
using Position = std::pair<int, int>;
using Board = std::set<Position>;
}

class ConvayWidget : public QWidget
{
    Q_OBJECT
public:

    ConvayWidget(QWidget*parent = nullptr);

    void advance();

    void toggleTimer(bool value);

    void setXoffset(int value);
    void setYoffset(int value);
    void setScaleFactor(int value);

    void setCrossSize(int size);

    void setAnimationSpeed(int ms);

signals:
    void fps(int);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    convay::Board board_;
    int x_offset_ = 210;
    int y_offset_ = 145;
    double scale_ = 0.275;

    QTimer timer;
};

#endif // CONVAYWIDGET_H
