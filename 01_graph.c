#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10

void dijkstra(int arr[MAX][MAX],int arr_length, int vertex,int distance[MAX],int previous[MAX])
{
	int cost[MAX][MAX], visited[MAX];
    int count,minDistance,next,i,j;
    
    for(i=0;i<arr_length;i++)
        for(j=0;j<arr_length;j++)
            if(arr[i][j]==0)
                cost[i][j]=99;
            else
                cost[i][j]=arr[i][j];
                
    for(i=0;i<arr_length;i++)
    {
        distance[i]=cost[vertex][i];
        previous[i]=vertex;
        visited[i]=0;
    }
    distance[vertex]=0;
    visited[vertex]=1;
    count=1;

    while(count<arr_length-1)
    {
        minDistance=99;
        for(i=0;i<arr_length;i++)
            if(distance[i]<minDistance&&!visited[i])
            {
                minDistance=distance[i];
                next=i;
            }
            visited[next]=1;
            for(i=0;i<arr_length;i++)
                if(!visited[i])
                    if(minDistance+cost[next][i]<distance[i])
                    {
                        distance[i]=minDistance+cost[next][i];
                        previous[i]=next;
                    }
        count++;
    }
}

int main()
{
	int i,j, distance[MAX],previous[MAX];
	srand(time(NULL));
	
	//-------------------------ОПРЕДЕЛЕНИЕ ДЛИННЫ МАССИВА С ПОМОЩЬЮ ЗАПИСИ В ФАЙЛ И ЧТЕНИЯ-----------------------------------//
	int arr_length; //основной размер массива
	int definitionLength; // вторичный, для определения второго
	
	// создаем файл для размера двумерного массива
	FILE *createLength;
	createLength = fopen("length.txt","wt");
	definitionLength = 4+rand()%7;
	fprintf(createLength,"%d ",definitionLength);
	fclose(createLength);
	
	//открываем для определения массива
	FILE *readLength;
	readLength = fopen("length.txt","r");
	fscanf(readLength, "%d ", &arr_length);
	fclose(readLength);
	
	//-------------------------ОПРЕДЕЛЯЕМ МАТРИЦУ СМЕЖНОСТИ С ПОМОЩЬЮ ЧТЕНИЕ ФАЙЛА---------------------------------------------//
	int arr[MAX][MAX]; // основаной массив
	int a[MAX][MAX]; // вторичный, для записи в файл рандомных чисел
	
	// создаем файл, записываем данные (a) в файл.
	FILE *createMatrix;
	createMatrix = fopen("matrix.txt","wt");
	for (i=0; i<arr_length; i++)
	{
		for(j=0;j<arr_length;j++)
		{
			if (i != j){
				a[i][j]=rand()%5;
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
	
	// считываем файл в (arr)
	FILE *readMatrix;
	readMatrix = fopen("matrix.txt","r");
	for (i=0; i<arr_length; i++)
	{
		for(j=0;j<arr_length;j++)
		{
			fscanf(readMatrix, "%d ", &arr[i][j]);
		}
	}
	fclose(readMatrix);
	
	//-------------------------ВЫБИРАЕМ НЕКОТОРУЮ ВЕРШИНУ ГРАФА ДЛЯ НАХОЖДЕНИЯ НАИКРОТЧАЙШИХ ПУТЕЙ ДО ВСЕХ ОСТАЛЬНЫХ ВЕРШИН--//
	int vertex; // вершина от которой ищет кратчайшие пути до остальных вершин
	int definitionVertex; // вторичный, для определения первого
	
	FILE *createVertex;
	createVertex = fopen("vertex.txt","wt");
	definitionVertex = rand()%11;
	while(definitionVertex >= arr_length){
		definitionVertex-=3;
	}
	fprintf(createVertex,"%d ",definitionVertex);
	fclose(createVertex);
	
	FILE *readVertex;
	readVertex = fopen("vertex.txt","r");
	fscanf(readVertex, "%d ", &vertex);
	fclose(readVertex);
		
	//-------------------------ВЫВОД МАТРИЦЫ СМЕЖНОСТИ И НАЧАЛЬНОЙ ВЕРШИНЫ----------------------------------------------------//
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
	printf("\nYour start vertex: %d\n",vertex);
	
	
	//-------------------------ПЕРЕХОД К ФУНКЦИИ---------------------------------------------------------------------------//
	FILE *saveResult;
	saveResult = fopen("result.txt","wt");
	for(i=0;i<arr_length;i++)
        if(i!=vertex)
        {
			dijkstra(arr,arr_length, vertex,distance, previous);
            fprintf(saveResult,"\nDistance of node %d from source %d =  %d",i, vertex, distance[i]);
            fprintf(saveResult,"\nPath = %d",i);
            printf("\nDistance of node %d from source %d =  %d",i, vertex, distance[i]);
            printf("\nPath = %d",i);
            j=i;
            do
            {
                j=previous[j];
                fprintf(saveResult,"<-%d",j);
                printf("<-%d",j);
            }while(j!=vertex);
        }
        
    fclose(saveResult);
	return 0;
}
