#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
 
void heapify(int arr[], int n, int i, int* countComparisons, int* countSwaps)
{
    int largest = i;  
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest])
    {
        (*countComparisons)++;
        largest = l;
    }
 
    if(r < n && arr[r] > arr[largest])
    {
        (*countComparisons)++;
        largest = r;
    }
 
    if(largest != i)
    {
        (*countSwaps)++; 
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, countComparisons, countSwaps);
    }
}
 
void heapSort(int arr[], int n, int* countComparisons, int* countSwaps)
{
	int i;
    for(i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, countComparisons, countSwaps);
    for(i = n - 1; i >= 0; i--)
    {
        (*countSwaps)++;
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, countComparisons, countSwaps);
    }
}

int main()
{
    
    int n, i, j, operation=0, sum_op=0;
    double average_op=0, sum_time_spent=0, average_time_spent=0;
    clock_t start, end;
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for(j=1;j<=1000;j++){
        int countComp = 0, countSwap = 0;
        printf("massif #%d\n", j);
        for(i=0;i<n;i++){
            arr[i]= rand()%1000;
            }
        start = clock();
        heapSort(arr, n, &countComp, &countSwap);
        end = clock();
        double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
        operation = countComp+countSwap;
        sum_op += operation;
        sum_time_spent += time_spent;
        printf("comparisons: %d , swaps: %d , operation: %d ,  execution Time: %f \n", countComp, countSwap, operation, time_spent);
    }
   	average_op=(double)sum_op/1000;
   	average_time_spent=sum_time_spent/1000;
    printf("\nnumber operation: %d , average number of operations: %f\nsum time ms: %f , average time ms: %f\n",sum_op, average_op,sum_time_spent, average_time_spent);
}
