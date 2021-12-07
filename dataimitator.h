#ifndef DATAIMITATOR_H
#define DATAIMITATOR_H

#include <QtBluetooth/QBluetoothTransferManager>
#include "windows.h"
#include "math.h"
#include <QObject>
#include <QThread>
#include <QPointF>
#include <windows.h>
#include <QtCore/QtMath>
#include <QVector>
#include <QtCore/QRandomGenerator>
#include <QMutex>
#include <QSerialPort>

class DataImitator: public QThread
{
    Q_OBJECT

public:
    explicit DataImitator(QVector<std::array<double, 5>> *seriesBuf, QMutex *mtx = nullptr);

    template<typename T>
    void CmdFlt(int n, T val);
    void SetWrkMode(int mode);
    bool ConnectCom(QString name);
    bool DisconnectCom();

public:

    size_t upd_ctr; //unsafe

private:
    void GetGraphData();
    void GetCommandData();

private:
    bool connected = false;
    LARGE_INTEGER frequency;
    LARGE_INTEGER t1,t2;
    QVector<std::array<double, 5>> *points;
    QVector<std::array<double, 5>> points_buf;
    QMutex *mtx_data_write;
    double PCFreq;
    volatile double elapsedTime;
    void timer_wait(double);
    double yprev;
    QSerialPort *m_serial = nullptr;
    bool prev_data_written;

    enum MODES{
        PREPARE = 0,
        GRAPH = 1,
    };
    size_t mode_grph;
    size_t mode_wrk;

 public Q_SLOTS:

   void run();
   void DataReady();
   void SetStart();
   void SetStop();

 Q_SIGNALS:

   void set_val(int num, double val);
};
template<typename T>
void DataImitator::CmdFlt(int n, T val)
{
    char cmdbuf[10];
    switch (n) {
    case 0:
        sprintf(cmdbuf,"mode %d;", mode_wrk);
        break;
    case 1:
        sprintf(cmdbuf,"zwco %.2lf;", val);
        break;
    case 2:
        sprintf(cmdbuf,"motf %d;", val);
        break;
    case 3:
        sprintf(cmdbuf,"tper %.2lf;", val);
        break;
    case 4:
        sprintf(cmdbuf,"totk %.2lf;", val);
        break;
    case 5:
        sprintf(cmdbuf,"a1vl %.2lf;", val);
        break;
    case 6:
        sprintf(cmdbuf,"h1vl %.2lf;", val);
        break;
    case 7:
        sprintf(cmdbuf,"k1vl %.2lf;", val);
        break;
    case 8:
        sprintf(cmdbuf,"x01v %.2lf;", val);
        break;
    case 9:
        sprintf(cmdbuf,"a2vl %.2lf;", val);
        break;
    case 10:
        sprintf(cmdbuf,"h2vl %.2lf;", val);
        break;
    case 11:
        sprintf(cmdbuf,"k2vl %.2lf;", val);
        break;
    case 12:
        sprintf(cmdbuf,"x02v %.2lf;", val);
        break;
    case 13:
        sprintf(cmdbuf,"kvos %.2lf;", val);
        break;
    case 14:
        sprintf(cmdbuf,"tvos %.2lf;", val);
        break;
    case 15:
        sprintf(cmdbuf,"extm %d;", val);
        break;
    case 20:
        sprintf(cmdbuf,"stx0 %.2lf;", val);
        break;
    default:
        break;

    }
    m_serial->write(QString::fromLocal8Bit(cmdbuf).toLocal8Bit());
}
#endif // DATAIMITATOR_H
