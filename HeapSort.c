  #include <stdio.h>
  
  // Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
 double heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    double hSortCTR = 0;
  	
  	hSortCTR++;
  	
    if (left < n && arr[left] > arr[largest])
    {
    	largest = left;
	}
      
    if (right < n && arr[right] > arr[largest])
    {
      	largest = right;
	}
    	
      
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
    	hSortCTR++;
	    swap(&arr[i], &arr[largest]);
	    hSortCTR += heapify(arr, n, largest);
    }
    
    return hSortCTR;
  }
  
  // Main function to do heap sort
  double heapSort(int arr[], int n) {
	  	int i;
    	double hSortCTR = 0;
    // Build max heap
    
    for (i = n / 2 - 1; i >= 0; i--)
    {
      	hSortCTR += heapify(arr, n, i);
    }
      
  
    // Heap sort
    for (i = n - 1; i >= 0; i--) {
      	swap(&arr[0], &arr[i]);
  
	    // Heapify root element to get highest element at root again
	    hSortCTR += heapify(arr, i, 0);
    }

    return hSortCTR;
  }