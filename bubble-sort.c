#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int list[], int size){
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j+1]){
                swap(&list[j], &list[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    
}

// int main(int argc, char* argv[]){
//     int* list = malloc(sizeof(int) * argc - 1);
//     for (int i = 0; i < argc - 1; i++)
//     {
//         list[i] = atoi(argv[i+1]);
//     }
//     bubbleSort(list, argc - 1);
//     for (int i = 0; i < argc - 1; i++)
//     {
//         printf("%d ", list[i]);
//     }
//     printf("\n");
// }