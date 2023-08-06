#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


int global_i = 0;

void* routine(){
     for( int i=1; i<=100000000; i++){
        global_i += 1;
     }
}


int main(int argc, char* argv[]){
    pthread_t thread1, thread2;
    
    if(pthread_create(&thread1, NULL, &routine, NULL) !=0){
        return 1;
    }
    if(pthread_create(&thread2, NULL, &routine, NULL) !=0){
        return 2;
    }
    if(pthread_join(thread1, NULL)!=0){
        return 3;
    }
    if(pthread_join(thread2, NULL)!=0){
        return 4;
    }

    printf("\ni=%d\n", global_i);
    return 0;
}




