#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int arr[], int arr_length, int* countComparisons, int* countSwaps)
{
    int i, j, k, t;
    for(k = arr_length / 2; k > 0; k /= 2)
    {
        for(i = k; i < arr_length; i++)
        {
            t = arr[i];
            for(j = i; j >= k; j -= k)
            {
            	(*countComparisons)++;
                if(t < arr[j - k]){
                    (*countSwaps)++;
                    arr[j] = arr[j - k];
                }
                else{
                    break;
            	}
            }
            arr[j] = t;
        }
    }
}

int main()    {
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
        shell(arr, n, &countComp, &countSwap);
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
