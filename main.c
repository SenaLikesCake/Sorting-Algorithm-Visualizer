#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

void draw(int list[], int size, int index, bool finished);
bool bubbleSort(int list[], int size, int* j);
void delay(int number_of_seconds);

int main(int argc, char* argv[]){
    const int SEGSIZE = 4096;
    
    int *list;
    int *index;
    bool *finished;
    list = mmap(NULL, SEGSIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    finished = mmap(NULL, 1, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    index = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    if(list == MAP_FAILED) exit(EXIT_FAILURE);
    if(finished == MAP_FAILED) exit(EXIT_FAILURE);
    if(index == MAP_FAILED) exit(EXIT_FAILURE);
    *finished = false;
    *index = 0;

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
            draw(list, size, *index, false);
        }
        draw(list, size, -1, true);
    }
    else{
        // printf("yay2\n");
        *finished = bubbleSort(list, size, index);
        // printf("nooo\n");
        exit(0);
    }
    
    
}