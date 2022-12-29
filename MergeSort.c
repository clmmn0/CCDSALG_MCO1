/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
  
double merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    double mSortCTR = 0;

    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
    {
      	L[i] = arr[l + i];
    }
         
    for (j = 0; j < n2; j++) 
    {
        R[j] = arr[m + 1 + j]; 
    }
        
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
      	mSortCTR++;
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    
    return mSortCTR;
    
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
double mergeSort(int arr[], int l, int r) 
{ 
   double mSortCTR = 0;
    
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mSortCTR += mergeSort(arr, l, m);
        mSortCTR += mergeSort(arr, m + 1, r); 
  
		mSortCTR += merge(arr, l, m, r); 
    } 

    return mSortCTR;
} 



// FINISHED (Note by Ralph, para lang maalala ko na nadaanan ko na ito)
    
    
