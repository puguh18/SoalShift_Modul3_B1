#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

static void* fact(void* arg){
    int n = *((int*)arg);
    unsigned long long fct = 1;
    for(int i = 1; i <= n; i++)
        fct = fct*i;
    printf("Hasil %d! = %llu\n", n, fct);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t *threads = NULL;
    threads = (pthread_t*)calloc(argc - 1, sizeof(pthread_t));
    int s, *nums = NULL;
    nums = (int*)calloc(argc - 1, sizeof(int));
    
    for(int i = 1; i < argc; i++){
        nums[i-1] = atoi(argv[i]);
        s = pthread_create(&threads[i-1], NULL, &fact, &nums[i-1]);
    }
    for(int i = 0; i < argc - 1; i++){
        s = pthread_join(threads[i], NULL);
    }
    free(threads);
    free(nums);
    return 0;
}
