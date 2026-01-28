
#include "thread.h"
thread::thread(QWidget *parent)
    :QThread(parent)
{

}

thread::~thread()
{

}

void thread::run()
{
    mutex.lock();
    //临界资源
    num--;
    mutex.unlock();

    //或者
    {
        QMutexLocker locker(&mutex);
        num--;
    }
}
