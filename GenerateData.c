#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void GenerateData(int nArray[], int nSize)
{
	int i;

	srand(time(NULL));

	for(i = 0; i < nSize; i++)
	{
		nArray[i] = rand();
	}
}


/*
int main()
{
	int n = 10, i;
	int A[n];

	GenerateData(A, n);

	for(i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}
	return 0;
}
*/