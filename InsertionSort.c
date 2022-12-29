// C program for insertion sort 
#include <math.h> 
#include <stdio.h> 

/* Function to sort an array using insertion sort*/
double insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
 	double iSortCTR = 0;
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 
		
		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
			
			iSortCTR++;
		} 
		arr[j + 1] = key; 
	} 

  return iSortCTR;
} 

// FINISHED (Note by Ralph, para lang maalala ko na nadaanan ko na ito)