#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100

// ջ�Ľṹ�嶨��
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

// ջ�ĳ�ʼ������
Status InitStack(SqStack &S)
{
    S.base=new SElemType[MAXSIZE];
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return OK;
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
    if(S.top == S.base) return true;
    else return false;
}

// �ж�ջ�ĳ���
int StackLength(SqStack S)
{
    return S.top-S.base;
}

// ���˳��ջ
Status ClearStack(SqStack &S)
{
    if(S.base) S.top=S.base;
    return OK;
}

// ����˳��ջ
Status DestroyStack(SqStack &S)
{
    if(S.base)
    {
        delete S.base;
        S.stacksize=0;
        S.base=S.top=NULL;
    }
    return OK;
}

// ˳���ջ
Status Push(SqStack &S,SElemType e)
{
    if(S.top-S.base==S.stacksize) return ERROR;//ջ��
        *S.top=e;
        S.top++;
        return OK;
}

// ˳���ջ
Status Pop(SqStack &S, SElemType &e)
{
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

// ȡ˳��ջ��Ԫ��
Status GetTop(SqStack S, SElemType &e)
{
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}

// ��ӡջ����
void PrintStack(SqStack S){
    for(SElemType* p=S.base;p<S.top;++p)
    {
        cout<< *p <<" ";
    }
    cout <<endl;
}

int main()
{
    SqStack S;
    if(InitStack(S) == OK){
        cout <<"Success init SqStack"<< endl;

        // ��ջѹ��Ԫ��
        for(int i=0;i<10;++i){
            if(Push(S,i)==OK){
                cout<<"Success push elem:"<<i<<endl;
            }else{
                cout<<"Error to push,SqStack filled"<<endl;
            }

        }

        //��ӡջ����
        cout << "now SqStack:";
        PrintStack(S);

        // ��ջ����Ԫ��
        SElemType popedelem;
        for(int i=0;i<5;i++){
            if(Pop(S, popedelem)==OK){
                cout << "Popped element:"<<popedelem<<endl;
            }else{
                cout << "Error to pop,SqStack empty"<<endl;
                break;
                }
        }

        // ȡջ��Ԫ��
        SElemType getedelem;
        if(GetTop(S, getedelem)==OK){
            cout <<"get top elem:"<<getedelem<<endl;
        }
    }else{
        cout<< "Error init SqStack" <<endl;
    }

    DestroyStack(S);
    return 0;
}
