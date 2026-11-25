#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *RESET = "\033[0m";
const char *RED = "\033[91m";
const char *GREEN = "\033[32m";
const char *GRAY = "\033[90m";

void draw(int list[], int size, int index, bool finished){
    char color1[10], color2[10];
    if (finished){
        strcpy(color1, GREEN);
        strcpy(color2, GRAY);
    }
    else{
        strcpy(color1, RESET);
        strcpy(color2, GRAY);
    }

    int max = list[0];
    system("clear");
    for (int i = 1; i < size; i++)
    {
        if (list[i] > max) max = list[i];
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (index == j) printf("%s", RED);
            else if (j % 2 == 0) printf("%s", color1);
            else printf("%s", color2);
            if (list[j] >= i){
                printf("##");
                // fflush(stdout);
            }
            else{
                printf("  ");
                // fflush(stdout);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < size; i++)
    {
        if (index == i) printf("%s", RED);
        else if (i % 2 == 0) printf("%s", color1);
        else printf("%s", color2);
        if (list[i] < 10) printf("0");
        printf("%d", list[i]);
    }
    printf("\n");
    
}
// int main(int argc, char* argv[]){
//     int list[] = {1, 5, 7, 2, 10, 9};
//     int size = 6;
//     draw(list, size);
// }