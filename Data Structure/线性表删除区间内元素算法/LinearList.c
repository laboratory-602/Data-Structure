//
//  LinearList.c
//  Data Structure
//
//  Created by Derek Chan on 2020/10/14.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef int ElementType;
typedef int Position;
typedef struct LNode *List;

struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

//MARK: -此函数创建线性表并实现线性表的输入,返回线性表的地址,元素从下标0开始存储
List ReadInput() {
    int n;
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L ->Last = -1;
    
    printf("请输入线性表元素个数：");
    scanf("%d",&n);//输入线性表的元素个数
    L->Last=n-1;
    printf("请输入线性表内元素：");
    for(int i=0;i<n;i++) {
        scanf("%d",&L->Data[i]);//输入线性表内元素
    }
    return L;
}

//MARK: -此函数实现线性表的输出
void PrintList( List L ) {
    int i;
    for(i=0;i<=L->Last;i++) {
        printf("%d",L->Data[i]);//输出删除区间内元素后的线性表
    }
}

//MARK: -删除函数
List Delete( List L, ElementType minD, ElementType maxD ) {
    Position n = L->Last ;
    int j=0;
    for(int i=0;i<=n;i++) {
        if(L->Data[i]<=minD || L->Data[i] >= maxD) {
            L->Data[j]=L->Data[i];
            j++;
        }
    }
    L->Last = j-1;
    
    return  L;
}

int main() {
    List L;
    ElementType minD, maxD;
//    int i;
    
    L = ReadInput();
    printf("请输入minD和maxD：");
    scanf("%d %d", &minD, &maxD);//输入所要删除区间
    L = Delete(L, minD, maxD);
    printf("删除后线性表为：");
    PrintList(L);
    
    return 0;
}

