#include <stdio.h>

#include <rtthread.h>
#include <pthread.h>

#define DBG_TAG "hello"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

void *main_thread_entry(void *arg)
{
    sleep(1);
    LOG_D("dynamic module sub thread execution successful.");

    return NULL;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    pthread_t main_thread = 0;
    struct pthread_attr pthread_attr_t;
    pthread_attr_init(&pthread_attr_t);

    pthread_attr_t.stacksize = 2048;
    pthread_attr_t.schedparam.sched_priority = 30;
    ret = pthread_create(&main_thread, &pthread_attr_t, main_thread_entry, NULL);
    if (ret != 0)
    {
        LOG_E("pthread_create error %d!", ret);
    }

    LOG_D("dynamic module wait for sub thread end...");
    void * pthread_result;
    ret = pthread_join(main_thread, &pthread_result);
    if (ret != 0)
    {
        LOG_E("pthread_join error %d!", ret);
    }

    LOG_D("dynamic module end.");

    //The main thread of the dynamic module cannot exit
    while(1)
    {
        sleep(1);
    }
    return 0;
}
