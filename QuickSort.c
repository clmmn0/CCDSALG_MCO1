
#include<stdio.h>

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
   
    // Function to swap the the position of two elements
void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
int partition (int arr[], int low, int high, double *qSortCTR) 
{ 
    int pivot = arr[high];    // pivot 
    int j;
    int i = (low - 1);  // Index of smaller element 
  	
    for (j = low; j <= high- 1; j++) 
    { 
    	(*qSortCTR)++;
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap2(&arr[i], &arr[j]); 
        } 
    } 
    swap2(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
double quickSort(int arr[], int low, int high) 
{ 
	double qSortCTR = 0;
	
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high, &qSortCTR); 
  
        // Separately sort elements before 
        // partition and after partition 
        qSortCTR += quickSort(arr, low, pi - 1); 
        qSortCTR += quickSort(arr, pi + 1, high); 
    } 
    
    return qSortCTR;
} 
