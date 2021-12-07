#include "dataimitator.h"
#include "stdio.h"
#include "QDebug"


DataImitator::DataImitator(QVector<std::array<double, 5>> *seriesBuf, QMutex *mtx)
{
    points = seriesBuf;
    QueryPerformanceFrequency(&frequency);
    PCFreq = double(frequency.QuadPart);
    mtx_data_write = mtx;
    m_serial = new QSerialPort(this);

    yprev = 0;
    prev_data_written = false;
    mode_grph = MODES::PREPARE;
    mode_wrk = 10;
}

bool DataImitator::ConnectCom(QString name)
{
    if(connected)
        return false;
    connect(m_serial, SIGNAL(readyRead()), this, SLOT(DataReady()));
    m_serial->setPortName(name);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serial->open(QIODevice::ReadWrite)) {
        m_serial->clear();
        {
            connected = true;
            mode_grph = MODES::PREPARE;
           return true;
        }

    } else
        return false;
}

bool DataImitator::DisconnectCom()
{
    if(!connected)
        return false;
    m_serial->close();
    connected= false;
    return true;
}


void DataImitator::timer_wait(double t_sample)
{
    QueryPerformanceCounter(&t1);
    do
    {
        QueryPerformanceCounter(&t2);

    }
    while (static_cast<double>(t2.QuadPart-t1.QuadPart)/PCFreq < t_sample);
}

void DataImitator::DataReady()
{
    if(mode_grph == MODES::GRAPH)
    {
        upd_ctr ++;
        GetGraphData();
    }
    if(mode_grph == MODES::PREPARE)
        GetCommandData();

}

void DataImitator::SetStart()
{
    if(!connected)
        return;
    upd_ctr = 0;
    CmdFlt(0, mode_wrk);
    mode_grph = MODES::GRAPH;
}

void DataImitator::SetStop()
{
    if(!connected)
        return;
    points->clear();
    points_buf.clear();
    prev_data_written = false;
    upd_ctr = 0;
    mode_grph = MODES::PREPARE;
    m_serial->clear();
    mode_wrk = 10;
    CmdFlt(0, mode_wrk);
}

void DataImitator::SetWrkMode(int mode)
{
    if(!connected)
        return;
    m_serial->clear();
    mode_wrk = mode;
    Q_EMIT(set_val(1, double(mode_wrk)));
}

void DataImitator::GetGraphData()
{
    qint64 dnum = 1;
    char cdat[70];

    if(prev_data_written){
       prev_data_written = false;
       points_buf.clear();
    }

    bool got_points = false;

    while(m_serial->bytesAvailable() >= 40)
    {

        dnum = m_serial->readLine(cdat, 45);
        if(dnum > 25){
            QStringList lst = QString::fromLocal8Bit(cdat).trimmed().split(" ");            
            if(lst.size() == 6)
            {
                double x = lst.at(1).toDouble();
                double y = lst.at(2).toDouble();
                double F = lst.at(3).toDouble();
                double t = lst.at(4).toDouble();
                double sigma = lst.at(5).toDouble();
                points_buf.append({t, x, y, sigma, F*100.0});
                got_points = true;
            }
        }

    }
    if(got_points && mtx_data_write->tryLock())
    {
        got_points = false;
        points->clear();
        points->append(points_buf);

        mtx_data_write->unlock();
        prev_data_written = true;
    }
}
void DataImitator::GetCommandData()
{
    qint64 dnum = 1;
    char comdat[50];

    while(m_serial->bytesAvailable() >= 10)
    {

        dnum = m_serial->readLine(comdat, 35);
        if(dnum > 10){
            QStringList lst = QString::fromLocal8Bit(comdat).trimmed().split(" ");
            if(lst.size() == 4)
            {
                QString par_name = lst.at(0);
                if(par_name == QString::fromLocal8Bit("mode"))
                {
                    //Q_EMIT(set_val(1, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("initial_w_z"))
                {
                    Q_EMIT(set_val(2, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("motor_torque"))
                {
                    Q_EMIT(set_val(3, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("tper"))
                {
                    Q_EMIT(set_val(4, lst.at(3).toDouble()/1000.0));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("totkl"))
                {
                    Q_EMIT(set_val(5, lst.at(3).toDouble()/1000.0));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("alpha1"))
                {
                    Q_EMIT(set_val(6, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("h1"))
                {
                    Q_EMIT(set_val(7, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("k1"))
                {
                    Q_EMIT(set_val(8, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("x01"))
                {
                    Q_EMIT(set_val(9, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("alpha2"))
                {
                    Q_EMIT(set_val(10, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("h2"))
                {
                    Q_EMIT(set_val(11, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("k2"))
                {
                    Q_EMIT(set_val(12, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("x02"))
                {
                    Q_EMIT(set_val(13, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("k_vos"))
                {
                    Q_EMIT(set_val(14, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("Tvos"))
                {
                    Q_EMIT(set_val(15, lst.at(3).toDouble()));
                    continue;
                }
                if(par_name == QString::fromLocal8Bit("ext_mom"))
                {
                    Q_EMIT(set_val(16, lst.at(3).toDouble()));
                    continue;
                }
            }
        }
    }
}

void DataImitator::run()
{
    if(!connected)
        return;
    while(1)
    {
        this->timer_wait(0.002);
        elapsedTime+=0.002;
        this->DataReady();
    }
}
