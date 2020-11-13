//
//  LinkedStorage.c
//  Data Structure
//
//  Created by Derek Chan on 2020/11/13.
//

//链式存储实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct SNode *PtrToSNode;

struct SNode {
    ElementType data;
    PtrToSNode next;
};

typedef PtrToSNode Stack;

Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->next = NULL;
    
    if (!S){
        printf("栈初始化失败\n");
        return 0;
    } else {
        return S;
    }
}

bool isEmpty(Stack S){
    return (S->next == NULL);
}

int Push(Stack S, ElementType X){
    PtrToSNode TmpCell;
    
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->data = X;
    TmpCell->next = S->next;
    S->next = TmpCell;
    return 1;
}

int Pop(Stack S){
    PtrToSNode firstCell;
    ElementType topEle;
    
    if (isEmpty(S)){
        printf("堆栈空\n");
        return -1;
    } else {
        firstCell = S->next;
        topEle = firstCell->data;
        S->next = firstCell->next;
        free(firstCell);
        return topEle;
    }
}

int Conversion(Stack S, int Num, int Radix) {
    int e;
    
    if (Radix == 0) {
        printf("基数不能为0\n");
        return 0;
    }
    
    while (Num) {
        Push(S, Num % Radix);
        Num = Num / Radix;
    }
    
    while (!isEmpty(S)) {
        e = Pop(S);
        printf("%d", e);
    }
    printf("\n");
    return 0;
}

int main(){
    int N,R;
    Stack S;
    
    S = CreateStack();
    
    printf("请输入一个十进制数：\n");
    scanf("%d", &N);
    printf("请输入转换后的数制：\n");
    scanf("%d", &R);
    Conversion(S, N, R);
    return 0;
}

