#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

static void* lohans_life(void *arg){
    int *temp = (int*)arg;
    while(*temp > 0 && temp <= 100){
        sleep(10);
        *temp -= 15;
    }
    return NULL;
}

static void* kepitings_life(void *arg){
    int *temp = (int*)arg;
    while(*temp > 0 && temp <= 100){
        sleep(20);
        *temp -= 10;
    }
    return NULL;
}

int main() {
    int status_l = 100;
    int status_k = 100;
    int k;
    pthread_t tid1, tid2;
    pthread_create(&(tid1), NULL, &lohans_life, &status_l);
    pthread_create(&(tid2), NULL, &kepitings_life, &status_k);
    while(1){
        printf("1. Feed Lohan  2. Feed Kepiting\n");
        scanf("%d", &k);
        if(k == 1) status_l += 10;
        if(k == 2) status_k += 10;
        printf("Status\n");
        printf("Lohan: %d\n", status_l);
        printf("Kepiting: %d\n", status_k);
    }
    return 0;
}
