#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

struct area {
    int area1[16];
    int area2[16];
    int point1;
    int point2;
    char name1[30];
    char name2[30];
};

int flag == 1;

static void* check(void* arg){
    while(1){
        int j, k;
        printf("%s\'s turn\n", a->name1);
        do {
            printf("Enter the number of your mine (1-4) >>");
            scanf("%d", &j);
        } while(j < 1 || j > 4)
        printf("Select the location of your MINE (1-16)\n");
        for(int i = 0; i < j; i++){
            do{
                scanf("%d", &k);
                a->area1[k-1] ? printf("Slot %d already filled\n", k):;
            } while (a->area1[k-1]);
            a->area1[k-1]++;
        }
        printf("%s\'s turn\n", a->name2);
        do {
            printf("Enter the number of your mine (1-4) >>");
            scanf("%d", &j);
        } while(j < 1 || j > 4)
        printf("Select the location of your MINE (1-16)\n");
        for(int i = 0; i < j; i++){
            do{
                scanf("%d", &k);
                a->area2[k-1] ? printf("Slot %d already filled\n", k):;
            } while (a->area2[k-1]);
            a->area2[k-1]++;
        }
        printf("%s\'s turn\n", a->name1);
        printf("Guess 4 of the %s\'s slot that has no MINE", a->name2);
        for(int i = 0; i < 4; i++){
            scanf("%d", &k);
            if(a->area2[k-1]){
                printf("Your guess is wrong, %s +1\n", a->name2);
                a->point2++;
            }
            else{
                printf("You guessed right, +1\n");
                a->point1++;
            }
        }
        printf("%s\'s turn\n", a->name2);
        printf("Guess 4 of the %s\'s slot that has no MINE", a->name1);
        for(int i = 0; i < 4; i++){
            scanf("%d", &k);
            if(a->area1[k-1]){
                printf("Your guess is wrong, %s +1\n", a->name1);
                a->point1++;
            }
            else{
                printf("You guessed right, +1\n");
                a->point2++;
            }
        }
        printf("Stats\n%s: %d\n%s: %d\n", a->name1, a->point1, a->name2, a->point2);
    }
    return NULL;
}

static void* play(void* arg){
    
    return NULL;
}

int main(){
    pthread_t tid1, tid2;
    struct area a;
    a.area1 = {0};
    a.area2 = {0};
    a.point1 = 0;
    a.point2 = 0;
    printf("Enter player1 name >>");
    scanf("%s", a.name[0]);
    printf("Enter player2 name >>");
    scanf("%s", a.name[1]);
    
    printf("Stats\n%s: %d\n%s: %d\n", a->name1, a->point1, a->name2, a->point2);
    return 0;
}
