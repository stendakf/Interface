#include "scopegraph.h"
#include <QtWidgets/QGesture>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtGui/QMouseEvent>
#include <QScrollBar>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    // Seems that QGraphicsView (QChartView) does not grab gestures.
    // They can only be grabbed here in the QGraphicsWidget (QChart).
    grabGesture(Qt::PanGesture);
    grabGesture(Qt::PinchGesture);
}

Chart::~Chart()
{

}

bool Chart::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent *>(event));
    return QChart::event(event);
}

bool Chart::gestureEvent(QGestureEvent *event)
{
    if (QGesture *gesture = event->gesture(Qt::PanGesture)) {
        QPanGesture *pan = static_cast<QPanGesture *>(gesture);
        QChart::scroll(-(pan->delta().x()), pan->delta().y());
    }

    if (QGesture *gesture = event->gesture(Qt::PinchGesture)) {
        QPinchGesture *pinch = static_cast<QPinchGesture *>(gesture);
        if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged)
            QChart::zoom(pinch->scaleFactor());
    }

    return true;
}

ChartView::ChartView(QChart *chart, QWidget *parent) :
    QChartView(chart, parent),
    m_isTouching(false)
{
    setRubberBand(QChartView::RectangleRubberBand);
}

bool ChartView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.
        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

void ChartView::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mousePressEvent(event);
}

void ChartView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mouseMoveEvent(event);
}

void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    chart()->setAnimationOptions(QChart::SeriesAnimations);

    QChartView::mouseReleaseEvent(event);
}


void ChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}

ScopeGraph::ScopeGraph(QWidget *parent) : QWidget(parent)
{
    thisChart = new QChart();
    chartView = new QChartView(thisChart,this);
    chartView->setMinimumSize(800,550);
    xAxis = new QValueAxis();
    yAxis = new QValueAxis();

    xAxis->setTitleText("x, град");
    xAxis->setLabelFormat("%d");
    xAxis->setTickCount(21);

    yAxis->setTitleText("y, град/c");
    yAxis->setLabelFormat("%d");
    yAxis->setTickCount(21);

    thisChart->addAxis(xAxis,Qt::AlignBottom);
    thisChart->addAxis(yAxis,Qt::AlignLeft);
    thisChart->legend()->hide();
    numSeries = 0;
}

void ScopeGraph::createSeries()
{
    thisChart->addSeries(new QLineSeries());
    thisChart->series().at(numSeries)->attachAxis(xAxis);
    thisChart->series().at(numSeries)->attachAxis(yAxis);
    numSeries++;
}

void ScopeGraph::set_XScale(double min, double max)
{
    xAxis->setRange(min,max);
}

void ScopeGraph::set_YScale(double min, double max)
{
    yAxis->setRange(min,max);
}

void ScopeGraph::Clear()
{
    QXYSeries *xySeries = static_cast<QXYSeries *>(thisChart->series().at(0));
    xySeries->clear();
    thisChart->update();
    chartView->repaint();
    this->repaint();
}

void ScopeGraph::update(QVector<QPointF> *data2plot, int index)
{
    //for(series) 
        QXYSeries *xySeries = static_cast<QXYSeries *>(thisChart->series().at(0));
        //QVector<QPointF> points = data2plot->at(index);
        // Use replace instead of clear + append, it's optimized for performance
        xySeries->replace(*data2plot);

   // }
}

OscChart::OscChart(QWidget *parent) : QWidget(parent)
{
    osc_chart = new QChart();
    chartView = new QChartView(osc_chart,this);
    chartView->setMinimumSize(800,180);
    xAxis = new QValueAxis();
    yAxis = new QValueAxis();
    osc_series_x = new QLineSeries();
    osc_series_y = new QLineSeries();
    xAxis->setRange(0, 1000);
    xAxis->setTitleText("t, мс");
    xAxis->setLabelFormat("%d");
    xAxis->setTickCount(11);
    yAxis->setLabelFormat("%d");

    osc_chart->addAxis(xAxis,Qt::AlignBottom);
    osc_chart->addAxis(yAxis,Qt::AlignLeft);
    osc_chart->addSeries(osc_series_x);
    osc_chart->addSeries(osc_series_y);
    osc_series_x->attachAxis(xAxis);
    osc_series_y->attachAxis(xAxis);
    osc_series_x->attachAxis(yAxis);
    osc_series_y->attachAxis(yAxis);

    osc_chart->legend()->hide();
    numSeries = 0;
    connect(xAxis, SIGNAL(rangeChanged(qreal, qreal)), parent, SLOT(sldr_update_resized(qreal, qreal)));
}

void OscChart::SetYRange(double val, int ticks){
    yAxis->setRange(-val, val);
    yAxis->setTickCount(ticks);

}

void OscChart::Update(QVector<QPointF> *data2plotx, QVector<QPointF> *data2ploty,int index)
{
        QXYSeries *xySeries = static_cast<QXYSeries *>(osc_chart->series().at(0));
        xySeries->replace(*data2plotx);
        QXYSeries *xySeries2            = static_cast<QXYSeries *>(osc_chart->series().at(1));
        xySeries2->replace(*data2ploty);
        double min = std::max(data2plotx->last().x() - 2000.0, 0.0);
        double max = std::max(data2plotx->last().x(), 2000.0);
        osc_chart->axisX()->setMin(min);
        osc_chart->axisX()->setMax(max);
}

void OscChart::SetWindow(int min, int max)
{
    xAxis->setRange(min, max);
}

void OscChart::set_XScale(double min, double max)
{
    xAxis->setRange(min,max);
}

void OscChart::set_YScale(double min, double max)
{
    yAxis->setRange(min,max);
}

void OscChart::Clear()
{
    QXYSeries *xySeries = static_cast<QXYSeries *>(osc_chart->series().at(0));
    QXYSeries *xySeries1 = static_cast<QXYSeries *>(osc_chart->series().at(1));
    xySeries->clear();
    xySeries1->clear();
    osc_chart->update();
    chartView->repaint();
    this->repaint();
}
