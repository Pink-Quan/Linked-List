#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node*Next;
}Node;

Node*CreatNode(int data);
Node*AddTail(int data,Node*head);
Node*AddHead(int data,Node*head);
void PrintAllList(Node*head);
int Length(Node*head);
Node*AddAt(int data, int loc,Node*head);
Node*DeleteAt(int loc,Node*head);
Node*DeleteHead(Node*head);
Node*DeleteTail(Node*head);
int TakeDataAt(int loc,Node*head);
int Search(int data,Node*head);

int main()
{
    Node*list=NULL;

    list=AddHead(1,list);
    list=AddHead(2,list);
    list=AddHead(3,list);
    list=AddTail(9,list);
    list=AddAt(1,99,list);
    //list=DeleteHead(list);
    //list=DeleteTail(list);
    PrintAllList(list);

    //printf("\n%d",TakeDataAt(8,list));
    printf("\n%d",Search(10,list));

    return 0;
}

Node*CreatNode(int data)
{
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->Next=NULL;

    return temp;
}

Node*AddHead(int data,Node*head)
{
    Node*temp=CreatNode(data);
    if(head==NULL)
        return temp;
    temp->Next=head;

    return temp;
}

Node*AddTail(int data,Node*head)
{
    Node*temp=CreatNode(data);
    if(head==NULL)
        return temp;
    Node*tail=head;
    while(tail->Next!=NULL)
        tail=tail->Next;
    tail->Next=temp;
    return head;
}

void PrintAllList(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->Next;
    }
}

int Length(Node*head)
{
    int i=0;
    Node*temp=head;
    while(temp!=NULL)
    {
        i++;
        temp=temp->Next;
    }
    return i;
}

Node*AddAt(int loc,int data,Node*head)
{
    int len=Length(head);
    Node*temp=CreatNode(data);
    Node*searching=head;

    if(head==NULL)
        return temp;
    if(loc>=len||loc<0)
        return head;

    int i=0;
    while(i!=loc-1)
    {
        searching=searching->Next;
        i++;
    }

    temp->Next=searching->Next;
    searching->Next=temp;

    return head;
}

Node*DeleteAt(int loc,Node*head)
{
    int len=Length(head);
    Node*searching=head;

    if(loc>=len||loc<0||head==NULL)
        return head;
    if(loc==0)
        return head->Next;

    int i=0;
    while(i!=loc-1)
    {
        searching=searching->Next;
        i++;
    }

    Node*optimize=searching->Next;

    searching->Next=searching->Next->Next;

    free(optimize);

    return head;
}

Node*DeleteHead(Node*head)
{
    if(head==NULL)
        return head;
    return head->Next;
}

Node*DeleteTail(Node*head)
{
    if(head==NULL)
        return head;

    Node*searching=head;
    int i=0,minusedLen=Length(head)-2;

    while(i!=minusedLen)
    {
        searching=searching->Next;
        i++;
    }

    Node*optimize=searching->Next;

    searching->Next=NULL;

    free(optimize);

    return head;
}

int TakeDataAt(int loc,Node*head)
{
    int len=Length(head);
    Node*searching=head;

    if(loc>=len||loc<0||head==NULL)
        return -1;

    int i=0;
    while(i!=loc)
    {
        searching=searching->Next;
        i++;
    }

    return searching->data;
}

int Search(int data,Node*head)
{
    int len=Length(head);
    Node*searching=head;

    if(head==NULL)
        return -1;

    int i=0;
    while(i<len)
    {
        if(searching->data==data)
            return i;
        searching=searching->Next;
        i++;
    }
    return -1;
}
