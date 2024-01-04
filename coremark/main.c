#include <stdio.h>

#include <rtthread.h>

int main(int argc, char *argv[])
{
    rt_kprintf("Hello, world\n");

    extern int core_mark(void);
    core_mark();

    return 0;
}

