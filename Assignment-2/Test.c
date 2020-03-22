#include "Heap.c"
void test1();
void test2();
void test3();
void test4();
void test5();

int main() {
    my_initialize_heap(1024); 
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}

void test1() {
    
    printf("Test case One\n");
    // Allocate an int
    int *a = my_malloc(sizeof(int));
    // print the address of the returned pointer
    printf("The address of pointer (int*)a: %p\n", a);
    // Free the int
    my_free(a);
    printf("a freed\n");
    /*  allocate another int 
        and print its address. 
        The addresses should be the same.
    */
    int *b = my_malloc(sizeof(int));
    printf("The address of pointer (int*)b: %p\n", a);
    my_free(b);
    printf("b freed\n");
}

void test2(){
    printf("Test case two\n");
    // Allocate two individual int values 
    int *p1 = my_malloc(sizeof(int));
    int *p2 = my_malloc(sizeof(int));
    // print their addresses. 
    // they should be exactly the size of your overhead plus the size of a void* apart.
    printf("The address of pointer (int*)p1: %p\n", p1);
    printf("The address of pointer (int*)p2: %p\n", p2);
    my_free(p1);
    my_free(p2);
    printf("p1 and p2 are freed\n");
}

void test3(){
    printf("Test case Three\n");
    // Allocate three int values and print their addresses.
    int *p1 = my_malloc(sizeof(int));
    int *p2 = my_malloc(sizeof(int));
    int *p3 = my_malloc(sizeof(int));
    printf("The address of (int*)p1: %p\n", p1);
    printf("The address of (int*)p2: %p\n", p2);
    printf("The address of (int*)p3: %p\n", p3);
    // free the second of the three.
    my_free(p2);
    printf("p2 are freed\n");
    // Allocate a double and print its address; 
    // verify that the address is the same as the int that you freed.
    p2 = my_malloc(sizeof(double));
    printf("The address of (double*)p2: %p\n", p2);
    my_free(p1);
    my_free(p2);
    my_free(p3);
    printf("p1, p2 and p3 freed.\n");
}

void test4(){
    printf("Test case Four\n");
    /*  Allocate one char, then allocate one int, and print their addresses.
        They should be exactly the same distance apart as in test #2.
    */
    char *p1 = my_malloc(sizeof(char));
    int *p2 = my_malloc(sizeof(int));
    printf("The address of (char*)p1: %p\n", p1);
    printf("The address of (int*)p2: %p\n", p2);
    my_free(p1);
    my_free(p2);
    printf("p1 and p2 freed.\n");
}

 void test5(){
     printf("Test case Five\n");
     /* Allocate space for a 100-element int array
        then for one more int value
        Verify that the address of the int value is 100 * sizeof(int) + the size of your header after the array's address. 
        Free the array. 
        Verify that the int's address and value has not changed.
        */
     int *p1 = my_malloc(100*sizeof(int));
     int *p2 = my_malloc(sizeof(int));
     printf("The address of (int*)p1: %p\n", p1);
     printf("The address of (int*)p2: %p\n", p2);
     my_free(p1);
     printf("p1 freed\n");
     printf("The address of (int*)p2: %p\n", p2);
     my_free(p2);
     printf("p2 freed\n");
 }
