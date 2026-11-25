#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

void draw(int list[], int size);
bool bubbleSort(int list[], int size);
void delay(int number_of_seconds);

int main(int argc, char* argv[]){
    const int SEGSIZE = 4096;
    
    int *list;
    bool *finished;
    list = mmap(NULL, SEGSIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    finished = mmap(NULL, 1, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    if(list == MAP_FAILED) exit(EXIT_FAILURE);
    if(finished == MAP_FAILED) exit(EXIT_FAILURE);
    *finished = false;

    int size;
    if (strcmp(argv[1], "-r") == 0){
        size = atoi(argv[2]);
        int min = atoi(argv[3]);
        int max = atoi(argv[4]);
        for (int i = 0; i < size; i++)
        {
            list[i] = rand() % (max - min + 1) + min;
        }
        
    }
    else{
        size = argc - 1;
        for (int i = 0; i < size; i++)
        {
            list[i] = atoi(argv[i+1]);
        }

    }

    pid_t pid = fork();
    if (pid > 0){
        // printf("yay1\n");
        while (!*finished)
        {
            delay(1);
            draw(list, size);
        }
    }
    else{
        // printf("yay2\n");
        *finished = bubbleSort(list, size);
        // printf("nooo\n");
        exit(0);
    }
    
    
}