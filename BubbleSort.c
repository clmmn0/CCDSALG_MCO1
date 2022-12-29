#include <stdio.h>

double bubbleSort(int list[], int n)
{
  int c, d, t;
  double bSortCTR = 0;

  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
		bSortCTR++;
      	if (list[d] > list[d+1]) {
      	  /* Swapping */
        	t         = list[d];
        	list[d]   = list[d+1];
        	list[d+1] = t;
      }
    }
  }

  return bSortCTR;
}


// FINISHED (Note by Ralph, para lang maalala ko na nadaanan ko na ito)