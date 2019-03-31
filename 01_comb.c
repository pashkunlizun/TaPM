#include <stdio.h>
#include <stdlib.h>

void comb(int *arr, int arr_length) {
	int i,t,count=0, compare =0;
	int step = arr_length;
	double fakt = 1.2473309;
	while (step >= 1)
	{
		for (i = 0; i + step < arr_length; i++)
		{
			if (arr[i] > arr[i+step])
			{
				compare++;
				count++;
				t=arr[i];
				arr[i] = arr[i+step];
				arr[i+step] = t;
			}
			else {
                compare++;
			}
		}
		step /=fakt;
	}
	    printf("number of permutations(perestanovki) = %d \nnumber of comparisons(sravnenie) = %d \n\n",count, compare);
}

int print(int *arr, int arr_len)	{
        int i;
        for(i = 0; i < arr_len; i++)	{
            printf("a[%d] = %d\n", i, arr[i]);
        }
        return 0;
}

int main()	{
  	int N,i;
  	printf("N = ");
  	scanf("%d",&N);
  	int a[N];
  	for (i = 0; i<N; i++)	{
  		printf("a[%d] = ",i);
    	scanf("%d", &a[i]);
	}
	printf("\n---After sorting Comb---\n\n");
	comb(a,N);
	print(a,N);
  	return 0;
}
