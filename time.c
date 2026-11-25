#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // Looping till required time is not achieved
    while (clock() - start_time < number_of_seconds * CLOCKS_PER_SEC / 10)
        ;
}