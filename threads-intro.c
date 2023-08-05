#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


void* routine(){
    printf("Threads is not Twitter\n");
    sleep(3);
    printf("It's just a lame copy\n");
}

int main(int argc, char* argv[]){
    pthread_t t1,t2;
    if(pthread_create(&t1, NULL, &routine,  NULL) != 0){
        printf("Thread t1 Failed \n");
        return 1;
    }
    if(pthread_create(&t2, NULL, &routine,  NULL) != 0){
        printf("Thread t2 Failed \n");
        return 2;
    }
    if(pthread_join(t1, NULL) != 0){
        printf("Thread t1 Failed \n");
        return 1;
    }
    if(pthread_join(t2, NULL) != 0){
        printf("Thread t2 Failed \n");
        return 2;
    }
    return 0;
}
