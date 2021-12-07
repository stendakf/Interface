#ifndef SCOPEGRAPH_H
#define SCOPEGRAPH_H

//#include <QQuickItem>

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


class ScopeGraph : public QWidget
{
    Q_OBJECT

public:
    explicit ScopeGraph(QWidget *parent = nullptr);
    void set_XScale(double min, double max);
    void set_YScale(double min, double max);
    void Clear();
//    void set_yAxis_scale();

    void createSeries();

private:

    QChartView * chartView;
    QChart *thisChart;
    QXYSeries *series;
    QValueAxis *xAxis, *yAxis;


    int numSeries;

signals:

public slots:
    void update(QVector<QPointF> *, int);

};

class OscChart: public QWidget
{
    Q_OBJECT
public:
    OscChart(QWidget *parent);
    void SetYRange(double val, int ticks);
    void Update(QVector<QPointF> *data2plotx, QVector<QPointF> *data2ploty, int index);
    void SetWindow(int min, int max);
    void set_XScale(double min, double max);
    void set_YScale(double min, double max);
    void Clear();

private:
    QChartView * chartView;
    QChart * osc_chart;
    QXYSeries *series;
    QValueAxis *xAxis, *yAxis;
    QLineSeries *osc_series_x ;
    QLineSeries *osc_series_y ;


    int numSeries;
};

#endif // SCOPEGRAPH_H
