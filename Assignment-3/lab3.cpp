#include <iostream>
#include <algorithm> 
#include <string.h>
#include <vector>
using namespace std;
struct Person {
    string name;
    int age;
};

template <typename T>
void bubbleSort(T arr[], int size);
int compare(Person const& p1, Person const& p2);
template<class T>
void printList(T arr[], int size);
void printStruct(Person arr[], int size);
/*
    type = 1 (int)
    type = 2 char)
    type = 3 (char)
    type = 4 (string)
    type = 5 (struct)
*/
int type;


template <typename T>
void bubbleSort(T arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(type > 0 && type < 5) {
                if(arr[j] > arr[j+1]) {
                    T temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    } 
}

// Compare function for struct type
// sort people alphabetically (lexicographically) by name
int compare(Person const& p1, Person const& p2) {
    if(p1.name == p2.name) {
        return p1.age < p2.age;
    }
    return p1.name < p2.name;
}
// sort people descending by age, where people of the same age should be sorted
// alphabetically
int compare2(Person const& p1, Person const& p2) {
	if(p1.age == p2.age) {
		return p1.name < p2.name;
	}
	return p1.age > p2.age;
}
template<class T>
void printList(T arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void printStruct(Person arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << (*((Person*)arr + i)).name << "-" << arr[i].age << " ";
    }
}
int main()
{
	int arr_size;

	// Sorting array of integers
    type = 1;
	int arr_int[] = { 5, 35, 1, 0, -45, 23, 12, 78, 435 };
	arr_size = sizeof(arr_int) / sizeof(arr_int[0]);
	bubbleSort(arr_int, arr_size);
	//sort(arr_int, arr_int + arr_size);
	printList(arr_int, arr_size);
	cout << "\n\n";

	// Sorting array of floating point values
    type = 2;
	float arr_float[] = { 645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26 };
	arr_size = sizeof(arr_float) / sizeof(arr_float[0]);
	bubbleSort(arr_float, arr_size);
	//sort(arr_float, arr_float + arr_size);
	printList(arr_float, arr_size);
	printf("\n\n");

	//Sorting array of characters
    type = 3;
	char arr_char[] = { 'z', 'y', 'a', 't', 'p', 'q', 'l', 'k' };
	arr_size = sizeof(arr_char) / sizeof(arr_char[0]);
	bubbleSort(arr_char, arr_size);
	//sort(arr_char, arr_char + arr_size);
	printList(arr_char, arr_size);
	printf("\n\n");

	// Sorting array of strings
    type = 4;
	string arr_string[] = { "apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant" };
	arr_size = sizeof(arr_string) / sizeof(arr_string[0]);
	bubbleSort(arr_string, arr_size);
	//sort(arr_string, arr_string + arr_size);
	printList(arr_string, arr_size);
	printf("\n\n");

	// Sorting array of structures
	Person arr_struct[] = { {"Hal", 20},
							{"Susann", 31},
							{"Dwight", 19}, 
							{"Kassandra",21},
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
							{"Natalie", 25} };
	arr_size = sizeof(arr_struct) / sizeof(arr_struct[0]);
	cout << "sort people alphabetically (lexicographically) by name \n";
	sort(arr_struct, arr_struct + arr_size, compare);
	printStruct(arr_struct, arr_size);
	cout << "Sort people descending by age and then alphabetically \n";
	// Sort people descending by age and then alphabetically 
	sort(arr_struct, arr_struct + arr_size, compare2);
	printStruct(arr_struct, arr_size);
	printf("\n\n");

	return 0;
}
