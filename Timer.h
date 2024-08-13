#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QTimer>
#include <QDateTime>

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

signals:
    void notice(QVariant data);

private slots:
    void timeOut();

public slots:
    void start();
    void stop();

private:
    QTimer m_timer;
    QString m_display;
};

#endif // TIMER_H
