#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>     // dynamic memory allocation
  

// -------------------------- Quick Sort --------------------------
// Function to swap two numbers
void swap(int* x, int* y){
    // *x Gives the value stored at variable x and assigns to variable t.
    int t = *x;
    // *y gives the value stored at variable y and assigns to *x
    *x = *y;
    // assign the value of t to *y
    *y = t;
}
// Places all smaller (smaller than pivot) to left of pivot
// and all greater elements to right of pivot
int partition (int *array, int left, int right, int pivot){
    bool flag = true;
    // Use two marker to compare the values on the right and left of the array to the pivot
    // Move pivot to the middle position
    while(flag == true){
        // Compare the value on the left to the pivot
        // If it is smaller then the pivot, keep moving
        while(left <= right && array[left] < pivot){
            // increments left index
            left++; 
        }
        // Compare the value on the right to the pivot
        // If it is greater then the pivot, keep moving
        while(left <= right && array[right] > pivot){
            // decrements right index
            right--; 
        }
        // Condition to make sure we the right index has to always greater than the left index
        if(left < right){
            // Swap two values if they are not in the correct positions
            swap(&array[left], &array[right]); 
        }
        // Otherwise stop the loop
        else{
            flag = false; // Stop the loop if all the elements are checked
            break;
        }
    }
    // return the value in the middle of the array
    return left;
}

void quickSort(int *array, int left, int right){
    // Return if the array is empty
    if(left >= right){
        return;
    }
    // Set the pivot to be the last element of the array
    int pivot = array[right];
    // find the middle position
    int mid = partition(array, left, right - 1, pivot);
    swap(&array[mid], &array[right]);
    // Recursively sort elements before 
    // partition and after partition 
    quickSort(array, left, mid - 1);
    quickSort(array, mid + 1, right);
    
}
// Call method quickSort
void qsort2(int* a, int n) {
    // Call quickSort method
    quickSort(a, 0, n - 1);
}
// ---------------------- End of Quick Sort --------------------------

// -------------------------- Merge Sort --------------------------
// Function to merge two subarray of the original array
void mergeArray(int *a, int left, int mid, int right){
    // size of the first sub-array
    int size1 = mid - left + 1;
    // size of the second sub-array
    int size2 = right - mid;
    int *temp = (int*) malloc(sizeof(int));
    
    // Merge the two temporary arrays back to the original array
    // Put smaller values first
    int i = left, j = mid + 1, k = 0; // Initial index of left subarray, right subarray, temporary array
    while( i <= mid && j <= right){
        // Compare the element on the Right subarray to the element on the Left subarray
        if(a[i] < a[j]){
            // Stores the element at index i of the left subarray in the temporary array
            *(temp + k++) = a[i++];
        }
        else{ // if element of right sub array is larger
            // Stores the element at index j to the temprary array
            *(temp + k++) = a[j++];
        }
    }
    // Loop through the rest of the Left subarray (if there's any)
    while(i <= mid){
        // Copy the remaining numbers into the temprary array
        *(temp + k++) = a[i++];
    }
    // Loop through the rest of the right subarray (if there's any)
    while(j <= right){
        // Copy the remaining numbers into the temprary array
        *(temp + k++) = a[j++];        
    }
    // Reset k to 0
    k = 0;

    while(left <= right){
        // copy elements of temporary array into the array
        a[left++] = *(temp + k++);
    }
    // release memory
    free(temp);
}
// left is for left index and right is right index of the 
//   sub-array of array to be sorted 
void mergeSort(int *array, int left, int right) {
    // Keep track of the index to make sure it doesn't overllap
    if(left < right) {
        // Get the middle index
        int mid = (left + right) / 2;
        // Sort the first haft of the array: from index 0 to middle index
        mergeSort(array, left, mid);
        // Sort the second haft of the array: from middle index to the last index
        mergeSort(array, mid + 1, right);
        // Merge two subarrays
        mergeArray(array, left, mid, right);
    }
}

// Call mergeSort function
void msort(int *a, int n) {
    mergeSort(a, 0, n - 1);
}
// Function to print all the elements in an array
void printArray(int array[], int size) {
    // Loop through the array
    for(int i = 0; i < size; i++){
        // Print the element at index i
        printf("%d ", array[i]);
    }
}
// Main function
int main() {
    // Given array
    int array[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int size = sizeof array / sizeof array[0];
    // Sort the array using quick sort
    qsort2(array, size);
    printf("Quick Sort\n");
    printArray(array, size);

    // Given array
    int array1[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    printf("\n Merge Sort: \n");
    // Sort the array using merged sort
    msort(array1, size);
    printArray(array1, size);
    return 0;
}





