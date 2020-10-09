//
//  deletedata.c
//  test
//
//  Created by Derek Chan on 2020/10/8.
//

#include <stdio.h>
#include "linklist.h"

typedef int datatype;

//删除
void deleteData(linklist L, datatype x, datatype y) {
    linklist pre = L, p, q = NULL;
    p = L ->next;
    while (p && p ->data <= x) {
        pre = p;
        p = p ->next;
    }
    
    while (p && p ->data <= y) {
        p = p ->next;
        q = pre ->next;
        pre ->next = p;
        pre = q ->next;
    }
    
    while (pre != p) {
        free(q);
        q = pre;
        pre = pre ->next;
    }
}

int main() {
    linklist head;
    int x, y;
    head = creatlinklist();
    print(head);
    printf("\n请输入要删除的数据区间:\n");
    scanf("%d %d", &x, &y);
    
    deleteData(head, x, y);
    print(head);
    
    return 0;
}
