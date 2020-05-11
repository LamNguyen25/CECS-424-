#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);
void swap(void *x, void *y);
// type of input
int type = 0;
/*
    type = 1 (int)
    type = 2 char)
    type = 3 (char)
    type = 4 (string)
    type = 5 (struct)
*/

// Person struct
typedef struct Person {
    char name[20];
    int age;
} Person;

// Swap function
void swap(void *x, void *y) {
    int a = *(int*)x;
    *(int*)x = *(int*)y;
    *(int*)y = a;
}
// compare two value depends on the type and return a number
int compare(const void *a, const void *b) {
    // type int
    if(type == 1) {
        return ((*(int*)a) - (*(int*)b));
    }
    else if(type == 2) { // type float
        return ((*(float*)a) - (*(float*)b));
    }
    else if(type == 3) { // type char
        return ((*(char*)a) - (*(char*)b));
    }
    else if(type == 4) { // type string
        return strcmp((*(char**)a), (*(char**)b));
    }
    else if(type == 5) { // type struct
        Person* p1 = (Person*)a;
        Person* p2 = (Person*)b;

        // if two person have the same name, then compare ages
        if(strcmp(p1->name, p2->name) == 0) {
            return (p1->age - p2->age);
        }
        else { // compare two names
            return strcmp(p1->name, p2->name);
        }  
    }
    else if(type == 6) { // sort people descending by age, where people of the same age should be sorted alphabetically
        Person* p1 = (Person*)a;
        Person* p2 = (Person*)b;

        // if two person have the same name, then compare ages
        if(p1->age == p2->age) {
            return strcmp(p1->name, p2->name);
        }
        else { // compare two names
            return (p1->age - p2->age);
        }  
    }
    return (*(int*)a - *(int*)b);
}


int main() {
    int size = 0;

    // Sorting array of integers
    type = 1;
    int arr_int[] = {3, 23, -27, 67, 0, 45, 1, 47, 154};
    size = sizeof(arr_int) / sizeof(arr_int[0]);
    qsort(arr_int, size, sizeof(int), compare);
    // Print the array
    for (int i = 0; i < size; i++)
    	printf("%d ", *((int*)arr_int + i));
    printf("\n");

    // Sorting array of float
    type = 2;
    float arr_float[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
    size = sizeof(arr_float) / sizeof(arr_float[0]);
    qsort(arr_float, size, sizeof(int), compare);
    // Print the array
    for (int i = 0; i < size; i++)
    	printf("%.2f ", *((float*)arr_float + i));
    printf("\n\n");


    // Sorting array of string
    type = 4;
    char* arr_string[] = {"ape", "durian", "health", "blue", "test", "ben", "chicken"};
	size = sizeof(arr_string) / sizeof(arr_string[0]);
	qsort(arr_string, size, sizeof(char*), compare);
    // Print the array
    for(int i = 0; i < size; i ++) {
        //int lengthOfString = strlen(arr_string[i]); 
        printf("%s", (char*)arr_string[i]);
        
        if(i < size) {
            printf(" ");
        }
    }
    printf("\n\n");

    // Sorting array of Person by name
    type = 5;
    struct Person arr_person[17] = {
                                        {"Hal", 20},
                                        {"Susann", 31},
                                        {"Dwight", 19},
                                        {"Kassandra", 21},
                                        {"Lawrence", 25},
                                        {"Cindy", 22},
                                        {"Cory", 27},
                                        {"Mac", 19},
                                        {"Romana", 27},
                                        {"Doretha", 32},
                                        {"Danna", 20},
                                        {"Zara", 23},
                                        {"Rosalyn", 26},
                                        {"Risa", 24},
                                        {"Benny", 28},
                                        {"Juan", 33},
                                        {"Natalie", 25}
                                    };
    size = sizeof(arr_person) / sizeof(arr_person[0]);
	qsort(arr_person, size, sizeof(Person), compare);
    Person* temp = (Person*)arr_person;
    printf("Order by name\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("%s-%d ", temp->name, temp->age);
			temp = ((Person*)temp + 1);

			if (i != size - 1)
				printf(" ");
		}

    // sort people descending by age, where people of the same age should be sorted alphabetically
    type = 6;
    size = sizeof(arr_person) / sizeof(arr_person[0]);
	qsort(arr_person, size, sizeof(Person), compare);
    Person* temp1 = (Person*)arr_person;
    printf("\n\nOrder by age and then name:\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("%s-%d ", temp1->name, temp1->age);
			temp1 = ((Person*)temp1 + 1);

			if (i != size - 1)
				printf(" ");
		}
}
