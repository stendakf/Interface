#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dataimitator.h>
#include <scopegraph.h>
#include <QVector>
#include <QPointF>
#include <QMutex>
#include <QTimer>
#include <QScrollBar>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum GRAPH
    {
        GR_TIME = 0,
        GR_X = 1,
        GR_Y = 2,
        GR_SIGMA = 3,
        GR_F = 4,
    };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Stop();
    void on_pushButton_clicked();
    void update_data();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_24_clicked();

    void on_com_choosen(QAction* com_ch);

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

public slots:
    void UpdateParam(int num, double val);
    void sldr_update_graph();
    void sldr_update_resized(qreal min, qreal max);

private:
    bool connected = false;
    QList<QSerialPortInfo> av_comp;
    QAction* com_ch_chosen;
    Ui::MainWindow *ui;
    ScopeGraph graph;
    QScrollBar graph_scroll;
    OscChart xychart;
    OscChart sigmfchart;
    QXYSeries *m_series;
    DataImitator *ADC;
    QVector<std::array<double, 5>> seriesData;
    QVector<QPointF> buf_ser_dat_phs, buf_ser_dat_tx, buf_ser_dat_ty, buf_ser_dat_tsig, buf_ser_dat_tf;
    bool first_val;
    double last_processed_time = 0;

    QMutex *mtx;
    QTimer *timer;
    size_t last_upd_ctr;
    size_t off_ctr;
    int max_data_size = 5000;
    int scroll_bar_rng = 2000;

    double x_plt = 0;
    bool running = false;
};

#endif // MAINWINDOW_H
