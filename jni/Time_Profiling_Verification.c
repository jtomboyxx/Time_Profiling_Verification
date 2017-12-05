#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <omp.h>

#include "Time_Profiling_Verification.h"

//#define MUTITHREAD_OFF

unsigned int getTimeOfMSecond();

int main()
{
    int ret = 0, sum = 0;
    int i, j;
    int width = 3840;
    int height = 2160;
    int count = 100;
    int size = width * height;
    unsigned char *data = (unsigned char*)malloc(size * sizeof(unsigned char) * count);

    clock_t start = clock();
    unsigned int main = getTimeOfMSecond();

#ifndef MUTITHREAD_OFF
    #pragma omp parallel for
#endif
    for (i = 0; i < size * count; i++)
    {
        data[i] = 255;
    }

    printf("[Profiling] system time : %d (ms)\n", getTimeOfMSecond() - main);
    printf("[Profiling] cpu time : %.2fs\n", (float)(clock() - start) / CLOCKS_PER_SEC);
    printf("[Profiling] clock - start: %.2f\n", (float)(clock() - start));
    printf("[Profiling] CLOCKS_PER_SEC : %.2f\n", (float)CLOCKS_PER_SEC);

    free(data);

    return ret;
}

unsigned int getTimeOfMSecond()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000+tv.tv_usec/1000;
}