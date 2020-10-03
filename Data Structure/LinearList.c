//
//  LinearList.c
//  Data Structure
//
//  Created by Derek Chan on 2020/10/3.
//

#include<stdio.h>
#include<stdlib.h>

#define ERROR -1

typedef int Position;
typedef int ElementType;
typedef struct LNode *PtrToLNode;

struct LNode {
    ElementType Data[6];
    Position Last;
};

typedef PtrToLNode List;

//MARK: -初始化
List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

//MARK: -查找

