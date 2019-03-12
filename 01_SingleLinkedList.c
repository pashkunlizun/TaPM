#include <stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *next;
} Node;

struct list{        
    struct Node* head;    
} list;


void init(struct list* l,int value)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->value=value;
    tmp->next=NULL;
    l->head = tmp;
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
    }
}

int isEmpty(struct list* l)
{
    return l->head==NULL;
}

struct Node* find(struct list* l,int value)
{
    struct Node *tmp=l->head;
    while(tmp->value!=value){
        if(tmp->next!=NULL)
            tmp=tmp->next;
        else
            return 0;
    }
    return tmp;
}


int push_back(struct list* l, int x)
{
    if(isEmpty(l)==1)
        init(l,x);
    else
    {
        struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->value=x;
        tmp->next=NULL;
        struct Node* temp = l->head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=tmp;
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
        tmp->next=l->head;
        l->head=tmp;
    }
    return 0;
}

int insertAfter (struct list* l,int num, int value)
{
    struct Node *temp = malloc(sizeof(Node));
    temp->value=value;

    struct Node* tmp = l->head;
    struct Node* prev_tmp = l->head;
    int i;
    
    for (i = 1;i<num+1;i++)
    {
        prev_tmp=tmp;
        tmp=tmp->next;
        if(tmp==NULL) 
            return -1;
    }
    prev_tmp->next=temp;
    temp->next=tmp;
    return 0;   
}


int removeFirst(struct list* l, int x)
{
    struct Node* element = find(l,x);
    if (element!=NULL){
        _remove(l,element);
        return 0;
    }
    return -1;
}

void _remove(struct list* l, struct Node *tmp){
    if(tmp!=NULL){
        if (tmp==l->head)
            l->head=tmp->next;
        else
        {
            struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
            temp=l->head;
            while(temp->next!=tmp)
                temp=temp->next;
            temp->next = tmp->next;
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
    for(i=0;i<3;i++){
        scanf("%d",&k[i]);
        if(find(l,k[i])!=NULL)
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    scanf("%d",&n);
    push_back(l,n);
    print(l);

    scanf("%d",&n);
    push_front(l,n);
    print(l);

    scanf("%d%d",&i,&n);
    insertAfter(l,i,n);
    print(l);

    scanf("%d",&n);
    removeFirst(l,n);
    print(l);

    clear(l);
    return 0;
}
