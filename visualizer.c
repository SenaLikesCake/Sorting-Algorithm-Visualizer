#include <stdio.h>
#include <stdlib.h>

void draw(int list[], int size){
    // printf("yay4\n");
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
}

// int main(int argc, char* argv[]){
//     int list[] = {1, 5, 7, 2, 10, 9};
//     int size = 6;
//     draw(list, size);
// }