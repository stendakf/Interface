#ifndef OSCCHART_H
#define OSCCHART_H

#include <QWidget>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>

QT_CHARTS_USE_NAMESPACE

class QGestureEvent;

class Chart : public QChart
{
public:
    explicit Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    ~Chart();

protected:
    bool sceneEvent(QEvent *event);

private:
    bool gestureEvent(QGestureEvent *event);

private:

};

class ChartView : public QChartView
{
public:
    ChartView(QChart *chart, QWidget *parent = 0);

protected:
    bool viewportEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    bool m_isTouching;
};



#endif // OSCCHART_H
