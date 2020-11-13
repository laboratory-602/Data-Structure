//
//  IncrementalLinkList.c
//  Data Structure
//
//  Created by Derek Chan on 2020/11/11.
//

//顺序存储实现
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *NodePtr;
struct Node {     /* 定义链表结点数据结构 */
    int Val;
    NodePtr Next;
};

int main() {
    int N, M;
    int i;
    NodePtr Head, Rear, Pre, Tmp;
    
    Head = Rear = (NodePtr)malloc(sizeof(struct Node));
    /* 为程序处理方便，构造表头空结点 */
    Head->Next = NULL;
    
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++) { /* 创建链表 */
        Pre = (NodePtr)malloc(sizeof(struct Node));    /* 申请新结点 */
        Pre->Next = NULL;
        scanf("%d", &Pre->Val);
        Rear->Next=Pre; /* 新结点插入链表尾部 */
        Rear = Pre;
    }
    /* 以下寻找M插入位置的前驱结点 */
    Pre = Head;
    while( Pre->Next != NULL && Pre->Next->Val<M) {
        Pre = Pre->Next;
    }
    /* 以下插入M */
    Tmp = (NodePtr)malloc(sizeof(struct Node));     /* 创建新结点 */
    Tmp->Val = M;
    Tmp->Next = Pre->Next; /* 插入新结点 */
    Pre->Next = Tmp;
    if(Pre == Rear){/* 插入表尾时,需修改Rear */
        Rear = Tmp;
    }
    /* 以下输出插入后的链表结果 */
    Tmp = Head->Next;
    printf("%d", Tmp->Val);
    for( Tmp=Tmp->Next; Tmp!= NULL; Tmp=Tmp->Next){
        printf(" %d", Tmp->Val);
    }
    printf("\n");
    
    return 0;
}

