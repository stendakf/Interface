#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDebug>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    graph(this),
    xychart(this),
    sigmfchart(this)
{
    ui->setupUi(this);
    mtx = new QMutex;
    ADC = new DataImitator(&seriesData, mtx);
    av_comp = QSerialPortInfo::availablePorts();
    for(auto & comp : av_comp)
    {
        ui->menu->addAction(comp.portName());
    }
    connect(ui->menu,SIGNAL(triggered(QAction* )),this, SLOT(on_com_choosen(QAction*)));
    connect(ADC, SIGNAL(set_val(int, double)), this, SLOT(UpdateParam(int, double)));
    ui->verticalLayout_2->addWidget(&graph);
    ui->verticalLayout_2->addWidget(&xychart);
    ui->verticalLayout_2->addWidget(&sigmfchart);
    graph.setMinimumSize(800,550);
    xychart.setMinimumSize(800,180);
    sigmfchart.setMinimumSize(800,180);
    xychart.SetYRange(120.0, 5);
    sigmfchart.SetYRange(120.0, 5);
    graph.createSeries();
    graph.set_XScale(-100.0, 100.0);
    graph.set_YScale(-100.0, 100.0);
    graph_scroll.setOrientation(Qt::Horizontal);
    ui->verticalLayout_2->addWidget(&graph_scroll);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(update_data()));
    graph_scroll.setMinimum(0);
    graph_scroll.setMaximum(2000);
    connect(&graph_scroll, SIGNAL(sliderReleased()), this, SLOT(sldr_update_graph()));
}

MainWindow::~MainWindow()
{
    ADC->terminate();
    delete ui;
}

 void MainWindow::on_com_choosen(QAction* com_ch)
 {
     if(ADC->ConnectCom(com_ch->text()))
     {
         com_ch_chosen = com_ch;
         connected = true;
     }
 }

void MainWindow::on_pushButton_clicked()
{
    if(!connected)
        return;
    if(running)
        return;
    running = true;
    last_upd_ctr = 0;
    off_ctr = 0;
    seriesData.clear();
    buf_ser_dat_phs.clear();
    buf_ser_dat_tx.clear();
    buf_ser_dat_ty.clear();
    buf_ser_dat_tsig.clear();
    buf_ser_dat_tf.clear();
    buf_ser_dat_phs.reserve(max_data_size);
    buf_ser_dat_tx.reserve(max_data_size);
    buf_ser_dat_ty.reserve(max_data_size);
    buf_ser_dat_tsig.reserve(max_data_size);
    buf_ser_dat_tf.reserve(max_data_size);
    timer->start(20);
    first_val = true;
    ADC->SetStart();
    last_processed_time = 0;
}

void MainWindow::update_data()
{
    if(ADC->upd_ctr == last_upd_ctr)
        off_ctr++;
    else
        last_upd_ctr = ADC->upd_ctr;

    if(off_ctr > 20000)
        Stop();


    int start = 0;
    const int availableSamples = seriesData.length();
    if(availableSamples == 0)
        return;
    if(seriesData.last()[0] == last_processed_time)
        return;
    else
        last_processed_time = seriesData.last()[0];

        if(first_val){
            first_val = false;           
            buf_ser_dat_phs.fill(QPointF(seriesData[0][GR_X],seriesData[0][GR_Y]), max_data_size);
            buf_ser_dat_tx.fill(QPointF(seriesData[0][GR_TIME],seriesData[0][GR_X]), max_data_size);
            buf_ser_dat_ty.fill(QPointF(seriesData[0][GR_TIME],seriesData[0][GR_Y]), max_data_size);
            buf_ser_dat_tsig.fill(QPointF(seriesData[0][GR_TIME],seriesData[0][GR_SIGMA]), max_data_size);
            buf_ser_dat_tf.fill(QPointF(seriesData[0][GR_TIME],seriesData[0][GR_F]), max_data_size);
        }


    if (availableSamples < max_data_size) {
        start = max_data_size - availableSamples;
        for (int s = 0; s < start; ++s)
        {
            buf_ser_dat_phs[s].setX(buf_ser_dat_phs.at(s + availableSamples).x());
            buf_ser_dat_phs[s].setY(buf_ser_dat_phs.at(s + availableSamples).y());
            buf_ser_dat_tx[s].setY(buf_ser_dat_tx.at(s + availableSamples).y());
            buf_ser_dat_tx[s].setX(buf_ser_dat_tx.at(s + availableSamples).x());
            buf_ser_dat_ty[s].setY(buf_ser_dat_ty.at(s + availableSamples).y());
            buf_ser_dat_ty[s].setX(buf_ser_dat_ty.at(s + availableSamples).x());
            buf_ser_dat_tsig[s].setY(buf_ser_dat_tsig.at(s + availableSamples).y());
            buf_ser_dat_tsig[s].setX(buf_ser_dat_tsig.at(s + availableSamples).x());
            buf_ser_dat_tf[s].setY(buf_ser_dat_tf.at(s + availableSamples).y());
            buf_ser_dat_tf[s].setX(buf_ser_dat_tf.at(s + availableSamples).x());
        }
    }

    for (int s = start; s < max_data_size; ++s)
    {
        buf_ser_dat_phs[s].setX(seriesData[s - start][GR_X]);
        buf_ser_dat_phs[s].setY(seriesData[s - start][GR_Y]);
        buf_ser_dat_tx[s].setX(seriesData[s - start][GR_TIME]);
        buf_ser_dat_tx[s].setY(seriesData[s - start][GR_X]);
        buf_ser_dat_ty[s].setX(seriesData[s - start][GR_TIME]);
        buf_ser_dat_ty[s].setY(seriesData[s - start][GR_Y]);
        buf_ser_dat_tsig[s].setX(seriesData[s - start][GR_TIME]);
        buf_ser_dat_tsig[s].setY(seriesData[s - start][GR_SIGMA]);
        buf_ser_dat_tf[s].setX(seriesData[s - start][GR_TIME]);
        buf_ser_dat_tf[s].setY(seriesData[s - start][GR_F]);
    }

    xychart.Update(&buf_ser_dat_tx, &buf_ser_dat_ty, 0);
    sigmfchart.Update(&buf_ser_dat_tsig, &buf_ser_dat_tf, 0);
    graph.update(&buf_ser_dat_phs,0);
    graph_scroll.setMaximum(std::max(2000, int (seriesData.last()[0])));
}

void MainWindow::UpdateParam(int num, double val)
{
   ;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(!connected)
        return;
   ADC->SetWrkMode(ui->lineEdit_4->text().toInt());
}

void MainWindow::on_pushButton_6_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt<double>(1, ui->lineEdit_5->text().toDouble());
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt<int>(2, ui->lineEdit_2->text().toInt());
}

void MainWindow::on_pushButton_4_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(3, ui->lineEdit_3->text().toDouble());
}


void MainWindow::on_pushButton_10_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(4, ui->lineEdit_6->text().toDouble());
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(5, ui->lineEdit->text().toDouble());
}

void MainWindow::on_pushButton_7_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(6, ui->lineEdit_7->text().toDouble());
}

void MainWindow::on_pushButton_8_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(7, ui->lineEdit_8->text().toDouble());
}

void MainWindow::on_pushButton_9_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(8, ui->lineEdit_9->text().toDouble());
}

void MainWindow::on_pushButton_11_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(9, ui->lineEdit_10->text().toDouble());
}

void MainWindow::on_pushButton_13_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(10, ui->lineEdit_11->text().toDouble());
}

void MainWindow::on_pushButton_14_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(11, ui->lineEdit_12->text().toDouble());
}

void MainWindow::on_pushButton_15_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(12, ui->lineEdit_13->text().toDouble());
}

void MainWindow::Stop()
{

    if(!connected)
        return;
    timer->stop();
    ADC->SetStop();
    running = false;
    FILE *f = fopen("C://standData/log.txt","w");
    if(!f)
        return;
    int i = 0;
    while((i + 1 <buf_ser_dat_phs.size())&&(buf_ser_dat_tx[i].x() <= 0.0))
        i++;
    while((i + 1 <buf_ser_dat_phs.size())&&(buf_ser_dat_tx[i].x() == buf_ser_dat_tx[i+1].x()))
        i++;
    for(; i < buf_ser_dat_phs.size(); ++i)
            fprintf(f, "%3.2lf %3.2lf %3.2lf %3.2lf %3.2lf\n", buf_ser_dat_tx[i].x()
                    , buf_ser_dat_tx[i].y(), buf_ser_dat_ty[i].y(), buf_ser_dat_tsig[i].y(), buf_ser_dat_tf[i].y());

    fclose(f);
}

void MainWindow::on_pushButton_12_clicked()
{
    if(!connected)
        return;
    this->Stop();
}

void MainWindow::on_pushButton_16_clicked()
{
    if(!connected)
        return;
   graph.Clear();
   xychart.Clear();
   sigmfchart.Clear();
   seriesData.clear();
   graph_scroll.setMaximum(2000);
   scroll_bar_rng = 2000;
   xychart.set_XScale(0, 2000);
   buf_ser_dat_phs.clear();
   buf_ser_dat_tx.clear();
   buf_ser_dat_ty.clear();
   buf_ser_dat_tsig.clear();
   buf_ser_dat_tf.clear();
}

void MainWindow::sldr_update_graph()
{
    int min = std::max(0, graph_scroll.value() - scroll_bar_rng);
    int max = std::min(min + scroll_bar_rng, graph_scroll.maximum());
    xychart.set_XScale(min, max);
    sigmfchart.set_XScale(min, max);
}

void MainWindow::sldr_update_resized(qreal min, qreal max)
{
    scroll_bar_rng = int(max - min);
    graph_scroll.setValue(int(max));
}

void MainWindow::on_pushButton_22_clicked()
{
    if(!connected)
        return;
    graph.set_XScale(ui->lineEdit_22->text().toDouble(),ui->lineEdit_23->text().toDouble());
}

void MainWindow::on_pushButton_23_clicked()
{
    if(!connected)
        return;
    graph.set_YScale(ui->lineEdit_24->text().toDouble(),ui->lineEdit_25->text().toDouble());
}

void MainWindow::on_pushButton_19_clicked()
{
    if(!connected)
        return;
    xychart.set_XScale(ui->lineEdit_16->text().toDouble(),ui->lineEdit_17->text().toDouble());
    sigmfchart.set_XScale(ui->lineEdit_16->text().toDouble(),ui->lineEdit_17->text().toDouble());
}

void MainWindow::on_pushButton_20_clicked()
{
    if(!connected)
        return;
    xychart.set_YScale(ui->lineEdit_18->text().toDouble(),ui->lineEdit_19->text().toDouble());
}

void MainWindow::on_pushButton_21_clicked()
{
    if(!connected)
        return;
    sigmfchart.set_YScale(ui->lineEdit_20->text().toDouble(),ui->lineEdit_21->text().toDouble());
}

void MainWindow::on_pushButton_17_clicked()
{
    if(!connected)
        return;
     ADC->CmdFlt(13, ui->lineEdit_14->text().toDouble());
}

void MainWindow::on_pushButton_18_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(14, ui->lineEdit_15->text().toDouble());
}

void MainWindow::on_pushButton_24_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(15, ui->lineEdit_26->text().toInt());
}

void MainWindow::on_pushButton_25_clicked()
{
    if(!connected)
        return;
    ADC->CmdFlt(20, ui->lineEdit_27->text().toFloat());
}

void MainWindow::on_pushButton_26_clicked()
{
    if(!connected)
        return;
    connected = false;
    com_ch_chosen->setChecked(false);
    ADC->DisconnectCom();
    this->Stop();
}
