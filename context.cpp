// measure the speed of context switch in Linux
// gcc context.c -lpthread

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

unsigned int Counter;
pthread_mutex_t LOCK;
pthread_cond_t CONDITION;

void * threads (void * unused) 
{
    pthread_mutex_lock(&LOCK);
    if (Counter > 0) {
        pthread_cond_signal(&CONDITION);
    }
    for (;;) {
        Counter++;
        pthread_cond_wait(&CONDITION, &LOCK);
        pthread_cond_signal(&CONDITION);
    }
    pthread_mutex_unlock(&LOCK);
}

int main(void)
{
    clock_t start, runtime;   /* start and end times */
    pthread_t t1, t2;

    pthread_mutex_lock(&LOCK);
    Counter = 0;
    pthread_create(&t1, NULL, threads, NULL);
    pthread_create(&t2, NULL, threads, NULL);
    pthread_detach(t1);
    pthread_detach(t2);
    start = clock();
    pthread_mutex_unlock(&LOCK);
    sleep(2);
    // Lock both simulaneous threads
    pthread_mutex_lock(&LOCK);
    //Normalize the result in second precision
    runtime = clock() - start;
    printf("Run time: %i, Counter: %i, Counter/sec: %i\n", runtime/1000, Counter, Counter/(runtime/1000));
}
