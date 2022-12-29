#include<stdio.h>
#include <processthreadsapi.h>
#include "BubbleSort.c"
#include "HeapSort.c"
#include "InsertionSort.c"
#include "MergeSort.c"
#include "SelectionSort.c"
#include "GenerateData.c"
#include "QuickSort.c"


double get_cpu_time()
{
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0){
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
            ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }else{
        //  Handle error
        return 0;
    }
}

double getMET(int A[], int AOrig[], int N, double *CV, int X)
{
	int i;
	double MET, begin, end;
	
	for(i = 0; i < N; i++) // makes sure that the original array does not change
	{
		A[i] = AOrig[i];
	}
	
	switch(X)
	{
		case 1:
			begin = get_cpu_time(); // computes for start cpu time 
			*CV = bubbleSort(A, N);
			end = get_cpu_time(); // computes for end cpu time
    		MET = (end - begin); // computes for MET
			break;
		case 2:
			begin = get_cpu_time(); // computes for start cpu time 
			*CV = heapSort(A, N);
			end = get_cpu_time(); // computes for end cpu time
    		MET = (end - begin); // computes for MET
			break;
		case 3:
			begin = get_cpu_time(); // computes for start cpu time 
			*CV = insertionSort(A, N);
			end = get_cpu_time(); // computes for end cpu time
    		MET = (end - begin); // computes for MET
			break;
		case 4:
			begin = get_cpu_time(); // computes for start cpu time 
			*CV = mergeSort(A, 0, N-1);
			end = get_cpu_time(); // computes for end cpu time
    		MET = (end - begin); // computes for MET
			break;
		case 5:
			begin = get_cpu_time(); // computes for start cpu time 
			*CV = selectionSort(A, N);
			end = get_cpu_time(); // computes for end cpu time
    		MET = (end - begin); // computes for MET
			break;
		case 6:
			begin = get_cpu_time(); // computes for start cpu time 
			*CV = quickSort(A, 0, N-1);
			end = get_cpu_time(); // computes for end cpu time
    		MET = (end - begin); // computes for MET
			break;
			
	}
		
	return MET;
}

double getAveMET(double MET[])
{
	int i;
	double aveMET = 0;
	
	for(i = 0; i < 10; i++)
	{
		aveMET += MET[i];
	}
	
	aveMET /= 10;
	
	return aveMET;
}

double getAveCV(double CV[])
{
	int i;
	double aveCV = 0;
	
	for(i = 0; i < 10; i++)
	{
		aveCV += CV[i];
	}
	
	aveCV /= 10;
	
	return aveCV;
}


int main()
{
	int N; 
	int M;
	int AOrig[1024], AOrig2[2048],AOrig3[4096], AOrig4[8192], AOrig5[16384], AOrig6[32768];
	int A[1024], A2[2048], A3[4096], A4[8192], A5[16384], A6[32768];
	double aveBubbleCV, aveHeapCV, aveInsertionCV, aveMergeCV, aveSelectionCV, aveQuickCV; // stores average counter variable for each sorting algo
	double BubbleCV[10], HeapCV[10], InsertionCV[10], MergeCV[10], SelectionCV[10], QuickCV[10]; // stores the counter variable for each M of all sorting algo, so in total 10 counter variables for each sorting algo
	// declared below are the variables for computing the MET and start, end cpu time. DI AKO SURE DITO HAHAHAH
    double BubbleMET[10], HeapMET[10], InsertionMET[10], MergeMET[10], SelectionMET[10], QuickMET[10];
	double aveBubbleMET, aveHeapMET, aveInsertionMET, aveMergeMET, aveSelectionMET, aveQuickMET;
	
	N = 1024; // set N
	
	for(M = 0; M < 10; M++) // initializes all values of counter variable & MET into 0
	{
		BubbleCV[M] = 0;
		BubbleMET[M] = 0;

		HeapCV[M] = 0;
		HeapMET[M] = 0;

		InsertionCV[M] = 0;
		InsertionMET[M] = 0;

		MergeCV[M] = 0;
		MergeMET[M] = 0;

		SelectionCV[M] = 0;
		SelectionMET[M] = 0;
		
		QuickCV[M] = 0;
		QuickMET[M] = 0;
	}
	
	GenerateData(AOrig, N);// generates random int for A[]

	for(M = 0; M < 10; M++)
	{
		BubbleMET[M] = getMET(A, AOrig, N, &BubbleCV[M], 1); // gets MET
		HeapMET[M] = getMET(A, AOrig, N, &HeapCV[M], 2); // gets MET
		InsertionMET[M] = getMET(A, AOrig, N, &InsertionCV[M], 3);
		MergeMET[M] = getMET(A, AOrig, N, &MergeCV[M], 4);
		SelectionMET[M] = getMET(A, AOrig, N, &SelectionCV[M], 5);
		QuickMET[M] = getMET(A, AOrig, N, &QuickCV[M], 6);
	}


/* the following code will now compute for the average MET & counter variable for each sorting algo*/

	printf("\n************************* AVERAGE if N = %d *************************\n", N); // delete, for display only
	aveBubbleMET = getAveMET(BubbleMET);
	aveBubbleCV = getAveCV(BubbleCV);
	printf("Average counter variable for Bubble Sort: %.0lf\n", aveBubbleCV);
	printf("Average MET for Bubble Sort: %lf\n\n", aveBubbleMET);
	
	aveHeapMET = getAveMET(HeapMET);
	aveHeapCV = getAveCV(HeapCV);
	printf("Average counter variable for Heap Sort: %.0lf\n", aveHeapCV);
	printf("Average MET for Heap Sort: %lf\n\n", aveHeapMET);

	aveInsertionMET = getAveMET(InsertionMET);
	aveInsertionCV = getAveCV(InsertionCV);
	printf("Average counter variable for Insertion Sort: %.0lf\n", aveInsertionCV);
	printf("Average MET for Insertion Sort: %lf\n\n", aveInsertionMET);

	aveMergeMET = getAveMET(MergeMET);
	aveMergeCV = getAveCV(MergeCV);
	printf("Average counter variable for Merge Sort: %.0lf\n", aveMergeCV);
	printf("Average MET for Merge Sort: %lf\n\n", aveMergeMET);
	
	aveSelectionMET = getAveMET(SelectionMET);
	aveSelectionCV = getAveCV(SelectionCV);
	printf("Average counter variable for Selection Sort: %.0lf\n", aveSelectionCV);
	printf("Average MET for Selection Sort: %lf\n\n", aveSelectionMET);
	
	aveQuickMET = getAveMET(QuickMET);
	aveQuickCV = getAveCV(QuickCV);
	printf("Average counter variable for Quick Sort: %.0lf\n", aveQuickCV);
	printf("Average MET for Quick Sort: %lf\n\n", aveQuickMET);
	
	//========================== 2048 ====================================================================================
	
	N = 2048; // set N
	
	for(M = 0; M < 10; M++) // initializes all values of counter variable & MET into 0
	{
		BubbleCV[M] = 0;
		BubbleMET[M] = 0;

		HeapCV[M] = 0;
		HeapMET[M] = 0;

		InsertionCV[M] = 0;
		InsertionMET[M] = 0;

		MergeCV[M] = 0;
		MergeMET[M] = 0;

		SelectionCV[M] = 0;
		SelectionMET[M] = 0;
		
		QuickCV[M] = 0;
		QuickMET[M] = 0;
	}
	
	GenerateData(AOrig2, N);// generates random int for A[]

	for(M = 0; M < 10; M++)
	{
		BubbleMET[M] = getMET(A2, AOrig2, N, &BubbleCV[M], 1); // gets MET
		HeapMET[M] = getMET(A2, AOrig2, N, &HeapCV[M], 2); // gets MET
		InsertionMET[M] = getMET(A2, AOrig2, N, &InsertionCV[M], 3);
		MergeMET[M] = getMET(A2, AOrig2, N, &MergeCV[M], 4);
		SelectionMET[M] = getMET(A2, AOrig2, N, &SelectionCV[M], 5);
		QuickMET[M] = getMET(A2, AOrig2, N, &QuickCV[M], 6);
	}


/* the following code will now compute for the average MET & counter variable for each sorting algo*/

	printf("\n************************* AVERAGE if N = %d *************************\n", N); // delete, for display only
	aveBubbleMET = getAveMET(BubbleMET);
	aveBubbleCV = getAveCV(BubbleCV);
	printf("Average counter variable for Bubble Sort: %.0lf\n", aveBubbleCV);
	printf("Average MET for Bubble Sort: %lf\n\n", aveBubbleMET);
	
	aveHeapMET = getAveMET(HeapMET);
	aveHeapCV = getAveCV(HeapCV);
	printf("Average counter variable for Heap Sort: %.0lf\n", aveHeapCV);
	printf("Average MET for Heap Sort: %lf\n\n", aveHeapMET);

	aveInsertionMET = getAveMET(InsertionMET);
	aveInsertionCV = getAveCV(InsertionCV);
	printf("Average counter variable for Insertion Sort: %.0lf\n", aveInsertionCV);
	printf("Average MET for Insertion Sort: %lf\n\n", aveInsertionMET);

	aveMergeMET = getAveMET(MergeMET);
	aveMergeCV = getAveCV(MergeCV);
	printf("Average counter variable for Merge Sort: %.0lf\n", aveMergeCV);
	printf("Average MET for Merge Sort: %lf\n\n", aveMergeMET);
	
	aveSelectionMET = getAveMET(SelectionMET);
	aveSelectionCV = getAveCV(SelectionCV);
	printf("Average counter variable for Selection Sort: %.0lf\n", aveSelectionCV);
	printf("Average MET for Selection Sort: %lf\n\n", aveSelectionMET);
	
	aveQuickMET = getAveMET(QuickMET);
	aveQuickCV = getAveCV(QuickCV);
	printf("Average counter variable for Quick Sort: %.0lf\n", aveQuickCV);
	printf("Average MET for Quick Sort: %lf\n\n", aveQuickMET);
	
	
	//========================== 4096 ====================================================================================
	
	N = 4096; // set N
	
	for(M = 0; M < 10; M++) // initializes all values of counter variable & MET into 0
	{
		BubbleCV[M] = 0;
		BubbleMET[M] = 0;

		HeapCV[M] = 0;
		HeapMET[M] = 0;

		InsertionCV[M] = 0;
		InsertionMET[M] = 0;

		MergeCV[M] = 0;
		MergeMET[M] = 0;

		SelectionCV[M] = 0;
		SelectionMET[M] = 0;
		
		QuickCV[M] = 0;
		QuickMET[M] = 0;
	}
	
	GenerateData(AOrig3, N);// generates random int for A[]

	for(M = 0; M < 10; M++)
	{
		BubbleMET[M] = getMET(A3, AOrig3, N, &BubbleCV[M], 1); // gets MET
		HeapMET[M] = getMET(A3, AOrig3, N, &HeapCV[M], 2); // gets MET
		InsertionMET[M] = getMET(A3, AOrig3, N, &InsertionCV[M], 3);
		MergeMET[M] = getMET(A3, AOrig3, N, &MergeCV[M], 4);
		SelectionMET[M] = getMET(A3, AOrig3, N, &SelectionCV[M], 5);
		QuickMET[M] = getMET(A3, AOrig3, N, &QuickCV[M], 6);
	}


/* the following code will now compute for the average MET & counter variable for each sorting algo*/

	printf("\n************************* AVERAGE if N = %d *************************\n", N); // delete, for display only
	aveBubbleMET = getAveMET(BubbleMET);
	aveBubbleCV = getAveCV(BubbleCV);
	printf("Average counter variable for Bubble Sort: %.0lf\n", aveBubbleCV);
	printf("Average MET for Bubble Sort: %lf\n\n", aveBubbleMET);
	
	aveHeapMET = getAveMET(HeapMET);
	aveHeapCV = getAveCV(HeapCV);
	printf("Average counter variable for Heap Sort: %.0lf\n", aveHeapCV);
	printf("Average MET for Heap Sort: %lf\n\n", aveHeapMET);

	aveInsertionMET = getAveMET(InsertionMET);
	aveInsertionCV = getAveCV(InsertionCV);
	printf("Average counter variable for Insertion Sort: %.0lf\n", aveInsertionCV);
	printf("Average MET for Insertion Sort: %lf\n\n", aveInsertionMET);

	aveMergeMET = getAveMET(MergeMET);
	aveMergeCV = getAveCV(MergeCV);
	printf("Average counter variable for Merge Sort: %.0lf\n", aveMergeCV);
	printf("Average MET for Merge Sort: %lf\n\n", aveMergeMET);
	
	aveSelectionMET = getAveMET(SelectionMET);
	aveSelectionCV = getAveCV(SelectionCV);
	printf("Average counter variable for Selection Sort: %.0lf\n", aveSelectionCV);
	printf("Average MET for Selection Sort: %lf\n\n", aveSelectionMET);
	
	aveQuickMET = getAveMET(QuickMET);
	aveQuickCV = getAveCV(QuickCV);
	printf("Average counter variable for Quick Sort: %.0lf\n", aveQuickCV);
	printf("Average MET for Quick Sort: %lf\n\n", aveQuickMET);

	
	//========================== 8192 ====================================================================================
	
	N = 8192; // set N
	
	for(M = 0; M < 10; M++) // initializes all values of counter variable & MET into 0
	{
		BubbleCV[M] = 0;
		BubbleMET[M] = 0;

		HeapCV[M] = 0;
		HeapMET[M] = 0;

		InsertionCV[M] = 0;
		InsertionMET[M] = 0;

		MergeCV[M] = 0;
		MergeMET[M] = 0;

		SelectionCV[M] = 0;
		SelectionMET[M] = 0;
		
		QuickCV[M] = 0;
		QuickMET[M] = 0;
	}
	
	GenerateData(AOrig4, N);// generates random int for A[]

	for(M = 0; M < 10; M++)
	{
		BubbleMET[M] = getMET(A4, AOrig4, N, &BubbleCV[M], 1); // gets MET
		HeapMET[M] = getMET(A4, AOrig4, N, &HeapCV[M], 2); // gets MET
		InsertionMET[M] = getMET(A4, AOrig4, N, &InsertionCV[M], 3);
		MergeMET[M] = getMET(A4, AOrig4, N, &MergeCV[M], 4);
		SelectionMET[M] = getMET(A4, AOrig4, N, &SelectionCV[M], 5);
		QuickMET[M] = getMET(A4, AOrig4, N, &QuickCV[M], 6);
	}


/* the following code will now compute for the average MET & counter variable for each sorting algo*/

	printf("\n************************* AVERAGE if N = %d *************************\n", N); // delete, for display only
	aveBubbleMET = getAveMET(BubbleMET);
	aveBubbleCV = getAveCV(BubbleCV);
	printf("Average counter variable for Bubble Sort: %.0lf\n", aveBubbleCV);
	printf("Average MET for Bubble Sort: %lf\n\n", aveBubbleMET);
	
	aveHeapMET = getAveMET(HeapMET);
	aveHeapCV = getAveCV(HeapCV);
	printf("Average counter variable for Heap Sort: %.0lf\n", aveHeapCV);
	printf("Average MET for Heap Sort: %lf\n\n", aveHeapMET);

	aveInsertionMET = getAveMET(InsertionMET);
	aveInsertionCV = getAveCV(InsertionCV);
	printf("Average counter variable for Insertion Sort: %.0lf\n", aveInsertionCV);
	printf("Average MET for Insertion Sort: %lf\n\n", aveInsertionMET);

	aveMergeMET = getAveMET(MergeMET);
	aveMergeCV = getAveCV(MergeCV);
	printf("Average counter variable for Merge Sort: %.0lf\n", aveMergeCV);
	printf("Average MET for Merge Sort: %lf\n\n", aveMergeMET);
	
	aveSelectionMET = getAveMET(SelectionMET);
	aveSelectionCV = getAveCV(SelectionCV);
	printf("Average counter variable for Selection Sort: %.0lf\n", aveSelectionCV);
	printf("Average MET for Selection Sort: %lf\n\n", aveSelectionMET);
	
	aveQuickMET = getAveMET(QuickMET);
	aveQuickCV = getAveCV(QuickCV);
	printf("Average counter variable for Quick Sort: %.0lf\n", aveQuickCV);
	printf("Average MET for Quick Sort: %lf\n\n", aveQuickMET);
	
	//========================== 16384 ====================================================================================
	
	N = 16384; // set N
	
	for(M = 0; M < 10; M++) // initializes all values of counter variable & MET into 0
	{
		BubbleCV[M] = 0;
		BubbleMET[M] = 0;

		HeapCV[M] = 0;
		HeapMET[M] = 0;

		InsertionCV[M] = 0;
		InsertionMET[M] = 0;

		MergeCV[M] = 0;
		MergeMET[M] = 0;

		SelectionCV[M] = 0;
		SelectionMET[M] = 0;
		
		QuickCV[M] = 0;
		QuickMET[M] = 0;
	}
	
	GenerateData(AOrig5, N);// generates random int for A[]

	for(M = 0; M < 10; M++)
	{
		BubbleMET[M] = getMET(A5, AOrig5, N, &BubbleCV[M], 1); // gets MET
		HeapMET[M] = getMET(A5, AOrig5, N, &HeapCV[M], 2); // gets MET
		InsertionMET[M] = getMET(A5, AOrig5, N, &InsertionCV[M], 3);
		MergeMET[M] = getMET(A5, AOrig5, N, &MergeCV[M], 4);
		SelectionMET[M] = getMET(A5, AOrig5, N, &SelectionCV[M], 5);
		QuickMET[M] = getMET(A5, AOrig5, N, &QuickCV[M], 6);
	}


/* the following code will now compute for the average MET & counter variable for each sorting algo*/

	printf("\n************************* AVERAGE if N = %d *************************\n", N); // delete, for display only
	aveBubbleMET = getAveMET(BubbleMET);
	aveBubbleCV = getAveCV(BubbleCV);
	printf("Average counter variable for Bubble Sort: %.0lf\n", aveBubbleCV);
	printf("Average MET for Bubble Sort: %lf\n\n", aveBubbleMET);
	
	aveHeapMET = getAveMET(HeapMET);
	aveHeapCV = getAveCV(HeapCV);
	printf("Average counter variable for Heap Sort: %.0lf\n", aveHeapCV);
	printf("Average MET for Heap Sort: %lf\n\n", aveHeapMET);

	aveInsertionMET = getAveMET(InsertionMET);
	aveInsertionCV = getAveCV(InsertionCV);
	printf("Average counter variable for Insertion Sort: %.0lf\n", aveInsertionCV);
	printf("Average MET for Insertion Sort: %lf\n\n", aveInsertionMET);

	aveMergeMET = getAveMET(MergeMET);
	aveMergeCV = getAveCV(MergeCV);
	printf("Average counter variable for Merge Sort: %.0lf\n", aveMergeCV);
	printf("Average MET for Merge Sort: %lf\n\n", aveMergeMET);
	
	aveSelectionMET = getAveMET(SelectionMET);
	aveSelectionCV = getAveCV(SelectionCV);
	printf("Average counter variable for Selection Sort: %.0lf\n", aveSelectionCV);
	printf("Average MET for Selection Sort: %lf\n\n", aveSelectionMET);
	
	aveQuickMET = getAveMET(QuickMET);
	aveQuickCV = getAveCV(QuickCV);
	printf("Average counter variable for Quick Sort: %.0lf\n", aveQuickCV);
	printf("Average MET for Quick Sort: %lf\n\n", aveQuickMET);
	
	
	//========================== 32768 ====================================================================================
	
	N = 32768; // set N
	
	for(M = 0; M < 10; M++) // initializes all values of counter variable & MET into 0
	{
		BubbleCV[M] = 0;
		BubbleMET[M] = 0;

		HeapCV[M] = 0;
		HeapMET[M] = 0;

		InsertionCV[M] = 0;
		InsertionMET[M] = 0;

		MergeCV[M] = 0;
		MergeMET[M] = 0;

		SelectionCV[M] = 0;
		SelectionMET[M] = 0;
		
		QuickCV[M] = 0;
		QuickMET[M] = 0;
	}
	
	GenerateData(AOrig6, N);// generates random int for A[]

	for(M = 0; M < 10; M++)
	{
		BubbleMET[M] = getMET(A6, AOrig6, N, &BubbleCV[M], 1); // gets MET
		HeapMET[M] = getMET(A6, AOrig6, N, &HeapCV[M], 2); // gets MET
		InsertionMET[M] = getMET(A6, AOrig6, N, &InsertionCV[M], 3);
		MergeMET[M] = getMET(A6, AOrig6, N, &MergeCV[M], 4);
		SelectionMET[M] = getMET(A6, AOrig6, N, &SelectionCV[M], 5);
		QuickMET[M] = getMET(A6, AOrig6, N, &QuickCV[M], 6);
	}


/* the following code will now compute for the average MET & counter variable for each sorting algo*/

	printf("\n************************* AVERAGE if N = %d *************************\n", N); // delete, for display only
	aveBubbleMET = getAveMET(BubbleMET);
	aveBubbleCV = getAveCV(BubbleCV);
	printf("Average counter variable for Bubble Sort: %.0lf\n", aveBubbleCV);
	printf("Average MET for Bubble Sort: %lf\n\n", aveBubbleMET);
	
	aveHeapMET = getAveMET(HeapMET);
	aveHeapCV = getAveCV(HeapCV);
	printf("Average counter variable for Heap Sort: %.0lf\n", aveHeapCV);
	printf("Average MET for Heap Sort: %lf\n\n", aveHeapMET);

	aveInsertionMET = getAveMET(InsertionMET);
	aveInsertionCV = getAveCV(InsertionCV);
	printf("Average counter variable for Insertion Sort: %.0lf\n", aveInsertionCV);
	printf("Average MET for Insertion Sort: %lf\n\n", aveInsertionMET);

	aveMergeMET = getAveMET(MergeMET);
	aveMergeCV = getAveCV(MergeCV);
	printf("Average counter variable for Merge Sort: %.0lf\n", aveMergeCV);
	printf("Average MET for Merge Sort: %lf\n\n", aveMergeMET);
	
	aveSelectionMET = getAveMET(SelectionMET);
	aveSelectionCV = getAveCV(SelectionCV);
	printf("Average counter variable for Selection Sort: %.0lf\n", aveSelectionCV);
	printf("Average MET for Selection Sort: %lf\n\n", aveSelectionMET);
	
	aveQuickMET = getAveMET(QuickMET);
	aveQuickCV = getAveCV(QuickCV);
	printf("Average counter variable for Quick Sort: %.0lf\n", aveQuickCV);
	printf("Average MET for Quick Sort: %lf\n\n", aveQuickMET);
	
	return 0;
}

