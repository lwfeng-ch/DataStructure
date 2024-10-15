#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;
LinkStack S;

void InitStack(LinkStack &S)
{
    S = NULL;
}

Status StackEmpty(LinkStack S)
{
    if(S==NULL) return TRUE;
    else return FALSE;
}

Status Push(LinkStack &S, SElemType e)
{
    StackNode *p = new StackNode;
    if(!p)exit(OVERFLOW);
    p->data = e; p->next=S; S=p;
    return OK;
}

Status Pop(LinkStack &S, SElemType &e)
{
    if(S==NULL) return ERROR;
    e = S->data; 
    StackNode *p=S;
    S=S->next; 
    delete p;
    return OK;
}

SElemType GetTop(LinkStack S)
{
    if(S==NULL)exit(1);
    else return S->data;
}

void PrintStack(LinkStack S)
{
    StackNode *p=S;
    while(p!=NULL)
    {
        cout<<p->data <<" ";
        p=p->next;
    }
    cout << endl;
}
int main()
{
    LinkStack S;
    InitStack(S);

    if(StackEmpty(S)==TRUE){
        cout<<"Stack is empty."<< endl;
    }

    for(int i=1;i<5;i++){
        Push(S, i);
        cout<<"Pushed elem:"<< i << endl;
    }

    cout<<"Current stack:";
    PrintStack(S);

    SElemType e;
    while(StackEmpty(S)==FALSE){
        Pop(S, e);
        cout<<"Poped element:" << e << endl;
    }

    if(StackEmpty(S)==TRUE){
        cout << "Stack is empty." << endl;
    }

    return 0;
}
