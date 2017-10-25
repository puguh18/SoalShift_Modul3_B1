#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

int flag = 0;

static void* lohans_life(void *arg){
    int *temp = (int*)arg;
    while(1){
        sleep(10);
        *temp -= 15;
    }
    return NULL;
}

static void* kepitings_life(void *arg){
    int *temp = (int*)arg;
    while(1){
        sleep(20);
        *temp -= 10;
    }
    return NULL;
}

static void* feed(void* arg){
    int *status = (int*)arg;
    int k;
    while(1){
        printf("1. Feed Lohan  2. Feed Kepiting  <other number for status>\n");
        scanf("%d", &k);
        if(k == 1) status[0] += 10;
        else if(k == 2) status[1] += 10;
        else {
            printf("Status\n");
            printf("Lohan: %d\n", status[0]);
            printf("Kepiting: %d\n", status[1]);
        }
    }
}

static void* check(void* arg){
    int *status = (int*)arg;
    while((status[0] > 0 && status[0] <= 100)&&(status[1] > 0 && status[1] <= 100));
    return NULL;
}

int main() {
    int status[2] = {100, 100};
    pthread_t tid[4];
    pthread_create(&(tid[0]), NULL, &lohans_life, &status[0]);
    pthread_create(&(tid[1]), NULL, &kepitings_life, &status[1]);
    pthread_create(&(tid[2]), NULL, &feed, status);
    pthread_create(&(tid[3]), NULL, &check, status);
    pthread_join(tid[3], NULL);
    printf("GAME OVER\n");
    printf("Status now\n");
    printf("Lohan: %d\n", status[0]);
    printf("Kepiting: %d\n", status[1]);
    return 0;
}
