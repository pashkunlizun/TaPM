#include <stdio.h>
#include<stdlib.h>

struct Node {
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

struct list{		
	struct Node* head;
	struct Node* tail;	
} list;


void init(struct  list* l,int value)
{
	struct Node* tmp;
	tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->value=value;
	tmp->next=NULL;
	tmp->prev=NULL;
	l->head = tmp;
	l->tail = tmp;
}

int clear(struct list* l)
{
	if(isEmpty(l)==1)
	{
		struct Node *tmp=l->head;
		struct Node *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
		l->head=NULL;
		l->tail=NULL;
	}
}

int isEmpty(struct list* l)
{
	return l->head==NULL && l->tail==NULL;
}

struct Node* find(struct list* l,int k)
{
	struct Node *tmp=l->head;
	while(tmp->value!=k){
		if(tmp->next!=NULL){
			tmp=tmp->next;
		}else{
			return 0;
		}
	}
	return tmp;
}

struct Node* find_invers(struct list* l,int k)
{
	struct Node *tmp=l->tail;
	while(tmp->value!=k){
		if(tmp->prev!=NULL){
			tmp=tmp->prev;
		}else{
			return 0;
		}
	}
	return tmp;
}

int push_back(struct list* l, int x)
{
	if(isEmpty(l)==1)
		init (l,x);
	else
	{
		struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->value=x;
		tmp->prev=l->tail;
		tmp->next=NULL;
		l->tail=tmp;
		tmp->prev->next=tmp;
	}
	return 0;
}

int push_front(struct list* l,int x) 
{
	if(isEmpty(l)==1)
		init (l,x);
	else
	{
		struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->value=x;
		tmp->prev=NULL;
		tmp->next=l->head;
		l->head=tmp;
		tmp->next->prev=tmp;
	}
	return 0;
}

int insertAfter	(struct list* l,int num, int data)
{
	struct Node* tmp = l->head;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL) 
			return 1;
	}
	struct Node *temp = malloc(sizeof(Node));
	temp->value=data;
	temp->next=tmp->next;
	temp->prev=tmp;
	tmp->next->prev=temp;
	tmp->next=temp;  
	return 0;   
}

int insertBefore(struct list* l,int num, int data)
{
	struct Node* tmp = l->head;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL) 
			return 1;
	}
	struct Node *temp = malloc(sizeof(Node));
	temp->value=data;
	temp->prev=tmp->prev;
	temp->next=tmp;
	tmp->prev=temp;
	temp->prev->next=temp;      
	return 0; 
}

int removeFirst(struct list* l, int x)
{
	struct Node* element = find(l,x);
	if (element!=NULL){
		_remove(l,element);
		return 0;
	}
	return 1;
}

int removeLast(struct list* l,int x)
{
	struct Node* element = find_invers(l,x);
	if (element!=NULL){
		_remove(l,element);
		return 0;
	}
	return 1;
}

void _remove(struct list* l, struct Node *tmp){
	if(tmp!=NULL){
		if (tmp==l->head && tmp==l->tail) {
			clear(l);
			return;
		}
		if (tmp==l->head)
		{
			l->head=tmp->next;
			tmp->next->prev=NULL;
		}
		else if(tmp==l->tail)
		{
			l->tail=tmp->prev;
			tmp->prev->next=NULL;
		}
		else if (tmp!=l->head && tmp!=l->tail)
		{
			tmp->next->prev=tmp->prev;
			tmp->prev->next=tmp->next;
		}
		free(tmp);
	}
}

void print(struct list* l)
{
	struct Node* tmp=l->head;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

void print_invers(struct list* l)
{
	struct Node* tmp=l->tail;
	while(tmp->prev!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->prev;
	}
	printf("%d\n", tmp->value);	
}



int main()
{
	int N,n,i;
	struct list* l=(struct list*)malloc(sizeof(struct list));	
	scanf("%d",&N);
	for (i=0;i<N;i++)
	{
		scanf("%d",&n);
		push_back(l,n);
	}
	print(l);
	
	int k[3];
	for(int i=0;i<3;i++){
		scanf("%d",&k[i]);
		if(find(l,k[i])!=NULL)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	scanf("%d",&n);
	push_back(l,n);
	print_invers(l);

	scanf("%d",&n);
	push_front(l,n);
	print(l);

	scanf("%d%d",&i,&n);
	insertAfter(l,i,n);
	print_invers(l);

	scanf("%d%d",&i,&n);
	insertBefore(l,i,n);
	print(l);

	scanf("%d",&n);
	removeFirst(l,n);
	print_invers(l);
	
	scanf("%d",&n);
	removeLast(l,n);
	print(l);

	clear(l);
	return 0;
}
