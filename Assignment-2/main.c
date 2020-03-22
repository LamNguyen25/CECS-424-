#include <math.h>
#include "Heap.c"

int main1() {
    int size = 0;
    int n = 0;
    int *ptr;
    double deviation = 0, u = 0;
    while(n <= 0) {
        printf("Please enter a positive integer: ");
        scanf("%d", &n);
        if( n < 0) {
            printf("Invalid input");
        }
    }
    size = n * sizeof(int);
    my_initialize_heap(size * 24);
    ptr = my_malloc(size);
    //printf("The address of (int*)ptr: %p\n", ptr);
    int k = 0;
    printf("Adding numbers to array\n");
    for(int i = 0; i < n ; i++){
        *(ptr + i) = i;
        u += *(ptr + i);
    }
    u /= n;
    // Calculate standard deviation
    for(int i = 0; i < n; i++){
        deviation += pow(*(ptr + i) - u,2);
    }
     deviation = sqrt( deviation / n);
     printf("Standard deviation = %f\n", deviation );
    return 0;
}