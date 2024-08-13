#include "Timer.h"

Timer::Timer(QObject *parent)
    : QObject{parent}
{
    connect(&m_timer, &QTimer::timeout, this, &Timer::timeOut);

    m_timer.setInterval(1000);
    m_display = "Starting...";

    qDebug() << Q_FUNC_INFO << m_display;

    emit notice(QVariant(m_display));
}

void Timer::timeOut()
{
    m_display = QDateTime::currentDateTime().toString();
    qDebug() << Q_FUNC_INFO << m_display;

    emit notice(QVariant(m_display));
}

void Timer::start()
{
    m_display = "Starting...";
    qDebug() << Q_FUNC_INFO << m_display;

    emit notice(QVariant(m_display));

    m_timer.start();
}

void Timer::stop()
{
    m_timer.stop();

    m_display = "Stopped...";
    qDebug() << Q_FUNC_INFO << m_display;

    emit notice(QVariant(m_display));
}
