#include <stdio.h>
#include <stdlib.h>


void draw(int list[], int size){
    const char *RESET = "\033[0m";     // Resets all attributes
    const char *RED = "\033[31m";      // Sets foreground color to red
    const char *GRAY = "\033[90m";     // Sets foreground color to bright black (often appears gray)

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
            if (j % 2 == 0) printf("%s", RESET);
            else printf("%s", GRAY);
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
        if (i % 2 == 0) printf("%s", RESET);
        else printf("%s", GRAY);
        if (list[i] < 10) printf("0");
        printf("%d", list[i]);
    }
    printf("\n");
    printf("%s", RESET);
    
}

// int main(int argc, char* argv[]){
//     int list[] = {1, 5, 7, 2, 10, 9};
//     int size = 6;
//     draw(list, size);
// }