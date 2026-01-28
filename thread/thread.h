#ifndef THREAD_H
#define THREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

class thread : public QThread
{
    Q_OBJECT
public:
    thread(QWidget* parent=nullptr);
    ~thread();

    void run() override;
signals:
    void notify();

private:
    static QMutex mutex;
    static int num;
};

#endif // THREAD_H
