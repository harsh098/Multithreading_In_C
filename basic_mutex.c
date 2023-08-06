#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int hits = 0;
pthread_mutex_t mutex;


void* routine(){
    for(int i=0; i<1000000; i++){
        pthread_mutex_lock(&mutex);
        hits++;
        pthread_mutex_unlock(&mutex);
    }
}



int main(){
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread1, thread2;
    if(pthread_create(&thread1, NULL, &routine,  NULL) != 0){
        printf("Thread1 Failed \n");
        return 1;
    }
    if(pthread_create(&thread2, NULL, &routine,  NULL) != 0){
        printf("Thread2 Failed \n");
        return 2;
    }
    if(pthread_join(thread1, NULL) != 0){
        printf("Thread1 Failed \n");
        return 1;
    }
    if(pthread_join(thread2, NULL) != 0){
        printf("Thread2 Failed \n");
        return 2;
    }
    printf("\nhits=%d\n", hits);
    pthread_mutex_destroy(&mutex);
}