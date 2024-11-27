#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

int main()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    printf("%ld, %ld\n", time.tv_sec, time.tv_usec);
    struct timeval now;

    sleep(1);
    gettimeofday(&now, NULL);
    printf("%ld", (now.tv_sec * 1000 + now.tv_usec / 1000) \
                - (time.tv_sec * 1000 + time.tv_usec / 1000));
    return 0;
}