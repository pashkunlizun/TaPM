#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 11

void mincost(int city, int arr[MAX][MAX],int arr_length, int *visited, int *cost,int begin, int *prov)
{
	int i,ncity;
	visited[city]=1;
	printf("%d--->",city);
	ncity=greedy(city, arr,arr_length,visited,cost,prov);
	if(ncity==999)
	{
		ncity=begin;
		printf("%d",ncity);
		*cost+=arr[city][ncity];
		return;
	}
	mincost(ncity,arr,arr_length,visited,cost,begin,prov);
}
int greedy(int c, int arr[MAX][MAX], int arr_length, int *visited,int *cost,int *prov)
{
	int i,nc=999;
	int min=999,kmin;
 	*prov+=1;
	for(i=0;i < arr_length;i++)
	{
        if((arr[i][c]!=0)&&(visited[i]==0)){
            if(arr[i][c] < min)
            {
                min=arr[i][c];
                kmin=arr[i][c];
                nc=i;
            }
        }
	}
	if(min!=999)
		*cost+=kmin;
 
	return nc;
}

void free_v(int *visited, int arr_length)
{
	int i;
	for (i=0; i<arr_length; i++)
	{
		visited[i] = 0;
	}
}
 
int main()
{
	int i, j, cost = 0, visited[MAX], weight[MAX];
	srand(time(NULL));
	
	//-------------------------ÎÏÐÅÄÅËÅÍÈÅ ÄËÈÍÍÛ ÌÀÑÑÈÂÀ Ñ ÏÎÌÎÙÜÞ ÇÀÏÈÑÈ Â ÔÀÉË È ×ÒÅÍÈß-----------------------------------//
	int arr_length; //îñíîâíîé ðàçìåð ìàññèâà
	int definitionLength; // âòîðè÷íûé, äëÿ îïðåäåëåíèÿ âòîðîãî
	
	// ñîçäàåì ôàéë äëÿ ðàçìåðà äâóìåðíîãî ìàññèâà
	FILE *createLength;
	createLength = fopen("length.txt","wt");
	definitionLength = 4+rand()%7;
	fprintf(createLength,"%d ",definitionLength);
	fclose(createLength);
	
	//îòêðûâàåì äëÿ îïðåäåëåíèÿ ìàññèâà
	FILE *readLength;
	readLength = fopen("length.txt","r");
	fscanf(readLength, "%d ", &arr_length);
	fclose(readLength);

	//-------------------------ÎÏÐÅÄÅËßÅÌ ÌÀÒÐÈÖÓ ÑÌÅÆÍÎÑÒÈ Ñ ÏÎÌÎÙÜÞ ×ÒÅÍÈÅ ÔÀÉËÀ---------------------------------------------//
	int arr[MAX][MAX]; // îñíîâàíîé ìàññèâ
	int a[MAX][MAX]; // âòîðè÷íûé, äëÿ çàïèñè â ôàéë ðàíäîìíûõ ÷èñåë
	
	// ñîçäàåì ôàéë, çàïèñûâàåì äàííûå (a) â ôàéë.
	FILE *createMatrix;
	createMatrix = fopen("matrix.txt","wt");
	for (i=0; i<arr_length; i++)
	{
		for(j=0;j<arr_length;j++)
		{
			if (i != j){
				a[i][j]=rand()%15;
				fprintf(createMatrix,"%d ",a[i][j]);
			}
			else{
				a[i][j] = 0;
				fprintf(createMatrix,"%d ",a[i][j]);
			}
		}
		fprintf(createMatrix,"\n");
	}
	fclose(createMatrix);
	
	// ñ÷èòûâàåì ôàéë â (arr)
	FILE *readMatrix;
	readMatrix = fopen("matrix.txt","r");
	for (i=0; i<arr_length; i++)
	{
		for(j=0;j<arr_length;j++)
		{
			fscanf(readMatrix, "%d ", &arr[i][j]);
		}
		visited[i] = 0;
	}
	fclose(readMatrix);
	
	//-------------------------ÂÛÂÎÄ ÌÀÒÐÈÖÛ ÑÌÅÆÍÎÑÒÈ È ÍÀ×ÀËÜÍÎÉ ÂÅÐØÈÍÛ----------------------------------------------------//
	printf("\nYour matrix: \n"); 
    for(i=0;i<arr_length;i++){
    	printf("  %d",i);
    }
    printf("\n");
    for(i=0;i<arr_length;i++){
    	printf("___",i);
    }
    printf("\n");
    for(i=0;i<arr_length;i++){
    	printf("%d|",i);
        for(j=0;j<arr_length;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
	}
	
		//-------------------------ÏÅÐÅÕÎÄ Ê ÔÓÍÊÖÈÈ---------------------------------------------------------------------------//
	FILE *saveResult;
	saveResult = fopen("result.txt","wt");
	int min, node, norma, prov=0;
	for(i=0;i<arr_length;i++)
	{
		prov=0;
		cost=0;
		free_v(visited,arr_length);
		printf("\n\nThe Path is:\n");
		mincost(i,arr,arr_length, visited, &cost,i,&prov);
		if (prov != arr_length){
			printf("\nCycle does not exist");
			weight[i]=999;
			continue;
		}
		printf("\nMinimum cost from %d is %d ",i,cost);
		weight[i]=cost;
	}
	min = weight[0];
	node=0;
	for(i=1;i<arr_length;i++)
	{
		if(min>weight[i]){
			min = weight[i];
			node = i;
		}
	}
	printf("\n\nMinimum cycle from %d is %d\n ",node,min);
	fprintf(saveResult,"\n\nMinimum cycle from %d is %d\n ",node,min);
	return 0;
}
 
