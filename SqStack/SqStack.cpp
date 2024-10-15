#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100

// 栈的结构体定义
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

// 栈的初始化函数
Status InitStack(SqStack &S)
{
    S.base=new SElemType[MAXSIZE];
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return OK;
}

// 判断栈是非为空
bool StackEmpty(SqStack S)
{
    if(S.top == S.base) return true;
    else return false;
}

// 判断栈的长度
int StackLength(SqStack S)
{
    return S.top-S.base;
}

// 清空顺序栈
Status ClearStack(SqStack &S)
{
    if(S.base) S.top=S.base;
    return OK;
}

// 销毁顺序栈
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

// 顺序进栈
Status Push(SqStack &S,SElemType e)
{
    if(S.top-S.base==S.stacksize) return ERROR;//栈满
        *S.top=e;
        S.top++;
        return OK;
}

// 顺序出栈
Status Pop(SqStack &S, SElemType &e)
{
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

// 取顺序栈顶元素
Status GetTop(SqStack S, SElemType &e)
{
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}

// 打印栈内容
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

        // 向栈压入元素
        for(int i=0;i<10;++i){
            if(Push(S,i)==OK){
                cout<<"Success push elem:"<<i<<endl;
            }else{
                cout<<"Error to push,SqStack filled"<<endl;
            }

        }

        //打印栈内容
        cout << "now SqStack:";
        PrintStack(S);

        // 从栈弹出元素
        SElemType popedelem;
        for(int i=0;i<5;i++){
            if(Pop(S, popedelem)==OK){
                cout << "Popped element:"<<popedelem<<endl;
            }else{
                cout << "Error to pop,SqStack empty"<<endl;
                break;
                }
        }

        // 取栈顶元素
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
