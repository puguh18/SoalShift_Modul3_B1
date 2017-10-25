#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>

char* types[] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};

void check(int *stock) {
    for(int i = 0; i < 6; i++)
        printf("%s : %d\n", types[i], stock[i]);
    putchar('\n');
}

void add(int *stock){
    char buff[10];
    int count, check = -1;
    printf("Enter weapon name and amount >>");
    scanf("%s %d", buff, &count);
    for(int i = 0; i < 6; i++)
        if(strcmp(buff, types[i]) == 0) check = i;
    if(check == -1) printf("ERROR: UNKNOWN WEAPON!!\n");
    else{
        stock[check] += count;
        printf("%s successfully added\n", types[check]);
        printf("%s now: %d\n", types[check], stock[check]);
    }
}

int main() {
    key_t key = 1234;
    int *stock;
    int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
    stock = shmat(shmid, NULL, 0);
    for (int i = 0; i < 6; i++) stock[i] = 0;
    
    while(1){
        int k;
        printf("WELKAM TO BLEK MEJIK WIPEN STOR\n");
        printf("~ seller mode ~\n");
        printf("1. Check Stock  2. Add Stock  <and other number to exit>\n");
        scanf("%d", &k);
        if(k == 1) check(stock);
        else if (k == 2) add(stock);
        else break;
    }

    shmdt(stock);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
