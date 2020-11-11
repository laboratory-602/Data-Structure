//
//  Stack.c
//  Data Structure
//
//  Created by Derek Chan on 2020/11/11.
//

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef int Position;
typedef struct SNode *PtrToSNode;

struct SNode {
    ElementType *Data;
    Position Top;
    int Maxsize;
};

typedef PtrToSNode Stack;

Stack CreateStack(int Maxsize) {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(Maxsize*sizeof(ElementType));
    S->Top = -1;
    S->Maxsize = Maxsize;
    return S;
}

void DestoryStack(Stack *S){
    if (*S) {
        free(*S);
    }
    *S = NULL;
    return;
}

int IsFull(Stack S){
    if (S->Top == S->Maxsize-1){
        return 1;
    } else {
        return 0;
    }
}

int IsEmpty(Stack S){
    if (S->Top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int Push(Stack S, ElementType X){
    if (IsFull(S)){
        printf("已满\n");
        return 0;
    } else {
        S->Data[++(S->Top)] = X;
        return 1;
    }
}

ElementType Pop(Stack S){
    if (IsEmpty(S)){
        printf("空\n");
        return 0;
    } else {
        return S->Data[(S->Top)--];
    }
}

int Conversion(int Num,int Radix) {
    Stack S;
    int tmp;
    if(Radix == 0) {
        printf("基数不能为0\n");
        return 0;
    }
    S = CreateStack(30);
    if(!S) {
        printf("栈初始化失败\n");
        return 0;
    }
    
    while (Num) {
        Push(S, Num % Radix);
        Num = Num / Radix;
    }
    
    while(!IsEmpty(S)) {
        tmp = Pop(S);
        printf("%d",tmp);
    }
    printf("\n");
    DestoryStack(&S);
    return 0;
}

int main(){
    int N,R;
    printf("请输入一个十进制数：\n");
    scanf("%d", &N);
    printf("请输入转换后的数制：\n");
    scanf("%d", &R);
    Conversion(N, R);
    return 0;
}

