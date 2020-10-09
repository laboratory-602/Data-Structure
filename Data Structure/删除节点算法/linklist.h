//
//  main.c
//  test
//
//  Created by Derek Chan on 2020/10/8.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}linknode;

typedef linknode *linklist;

// MARK： 尾插法创建带头结点的单链表
linklist creatlinklist() {
    linklist head, r, s;
    int x;
    head = r = (linklist)malloc(sizeof(linknode));
    printf("\n请输入一组以0结束的整数序列： \n");
    scanf("%d", &x);

    while (x) {
        s = (linklist)malloc(sizeof(linknode));
        s ->data = x;
        r ->next = s;
        r = s;
        scanf("%d", &x);
    }
    r ->next = NULL;
    return head;
}

//MARK：输出带头结点的单链表
void print(linklist L) {
    linklist p;
    p = L ->next;
    printf("List is:\n");
    
    while (p) {
        printf("%5d", p ->data);
        p = p ->next;
    }
    printf("\n");
}
