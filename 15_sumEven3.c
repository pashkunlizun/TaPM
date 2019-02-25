#include<stdio.h>

int main()
{
    int N ,n;
    int i = 0, sum = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
    	scanf("%d", &n);
    	if ((i+1)%2==0)
		{
    		sum += n*n*n;
		}
	}
    printf("%d",sum);
}
