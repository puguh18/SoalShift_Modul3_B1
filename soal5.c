#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

static void* finding(void* arg){
    FILE *f = fopen("Novel.txt", "r");
    if (f == NULL) exit(1);
    int c = 0;
    char buff[50];
    char* n = *((char**)arg);
    while(fscanf(f, "%s", buff) != EOF){
        if(!isalnum(buff[strlen(buff)-1]))
            buff[strlen(buff)-1] = '\0';
        if (strcmp(buff, n) == 0)
            c++;
    }
    printf("%s : %d\n", n, c);
    fclose(f);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t *threads = NULL;
    threads = (pthread_t*)calloc(argc - 1, sizeof(pthread_t));
    int s; 
    char **find = NULL;
    find = (char**)calloc(argc - 1, sizeof(char*));
    
    for(int i = 1; i < argc; i++){
        find[i-1] = argv[i];
        s = pthread_create(&threads[i-1], NULL, &finding, &find[i-1]);
    }
    for(int i = 0; i < argc - 1; i++){
        s = pthread_join(threads[i], NULL);
    }
    free(threads);
    free(find);
    return 0;
}
