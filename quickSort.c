#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qs(int *arr, int left, int right, int* countComparisons, int* countSwaps)
{
    int i, j, x, y;
    
    i = left; j = right;
    x = arr[(left+right)/2]; 
    
    do  {
        while ((arr[i] < x) && (i < right)) i++;
        while ((x < arr [j]) && (j > left)) j--;
        (*countComparisons)++;
        if (i <= j) {
        	(*countSwaps)++;
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++; j--;
        }
    }   while (i <= j);
    
    if (left < j) qs(arr, left, j, countComparisons, countSwaps);
    if (i < right) qs (arr, i, right, countComparisons, countSwaps);
}

int main()	{
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
        qs(arr, 0, n-1, &countComp, &countSwap);
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
