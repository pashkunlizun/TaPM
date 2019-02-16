#include<stdio.h>
#include<math.h>
int main()
{
    int a ,b;
    printf("Please enter the number and its degree: ");
    scanf("%d %d", &a, &b);
    b=pow(a,b);
    printf("%d",b);
}
