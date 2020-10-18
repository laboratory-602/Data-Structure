//
//  Queue.c
//  Data Structure
//
//  Created by Derek Chan on 2020/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
typedef int ElementType;
typedef int Position;
typedef struct QNode *PtrToNode;
typedef enum { addq, delq, end } Operation;

struct QNode {
    ElementType *Data;
    Position Front;
    int Count;
    int MaxSize;
};
typedef PtrToNode Queue;

//MARK: -创建队列
Queue CreateQueue(int MaxSize) {
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = 0;
    Q->Count = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

//MARK: -入队操作函数
bool AddQ(Queue Q, ElementType X) {
    if (Q->Count == Q->MaxSize)
    {
        printf("Queue Full\n");
        return false;
    }
    Q->Count++;
    Q->Data[(Q->Front + Q->Count) % Q->MaxSize] = X;
    return true;
}

//MARK: -出队操作函数
ElementType DeleteQ(Queue Q) {
    if (Q->Count == 0) {
        printf("Queue Empty\n");
        return ERROR;
    }
    Q->Count--;
    Q->Front = (Q->Front+1) % Q->MaxSize;
    return Q->Data[Q->Front];
}

Operation GetOp(void); //GetOp函数暂时没有解决思路

int main(){
    ElementType X;
    Queue Q;
    int N, done = 0;
    
    scanf("%d", &N);
    Q = CreateQueue(N);
    while (!done) {
        switch(GetOp()) {
            case addq:
                scanf("%d", &X);
                AddQ(Q, X);
                break;
            case delq:
                X = DeleteQ(Q);
                if ( X!=ERROR ) printf("%d is out\n", X);
                break;
            case end:
                while (Q->Count) printf("%d ", DeleteQ(Q));
                done = 1;
                break;
        }
    }
    return 0;
}




