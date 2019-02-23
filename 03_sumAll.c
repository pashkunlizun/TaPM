#include<stdio.h>

int main()
{
    int N ,n;
    int i=0;
    scanf("%d", &N);
    int sum = 0;
    for (i = 0; i < N; i++)
    {
    	scanf("%d", &n);
    	sum += n;
	}
    printf("sum: %d",sum);
}
