//
//  DuplicateTheBinaryTree.c
//  Data Structure
//
//  Created by Derek Chan on 2020/11/27.
//

#include <stdio.h>
#include <stdlib.h>

#define Maxsize 1000

typedef struct TNode{
    char data;
    struct TNode *left, *right;
} BinTreeNode;

BinTreeNode *CreateBinTree(char *data, int pos) {
    BinTreeNode *treeNode;
    if (data[pos] == 0 || pos > Maxsize) {
        return NULL;
    } else {
        treeNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        treeNode->data = data[pos];
        treeNode->left = CreateBinTree(data, 2*pos);
        treeNode->right = CreateBinTree(data, 2*pos+1);
        return treeNode;
    }
}

BinTreeNode *BTreeCopy(BinTreeNode* BT) {
    BinTreeNode *newTreeRoot;

    if (BT == NULL) {
        return NULL;
    } else {
        newTreeRoot = (BinTreeNode*)malloc(sizeof(struct TNode));
        newTreeRoot->data = BT->data;
        newTreeRoot->left = BTreeCopy(BT->left);
        newTreeRoot->right = BTreeCopy(BT->right);
    }
    return newTreeRoot;
}

void PreOlder(BinTreeNode *BT) {
    if (BT){
        printf("%c", BT->data);
        PreOlder(BT->left);
        PreOlder(BT->right);
    }
}

void InorderTraversal(BinTreeNode *BT) {
    if (BT) {
        InorderTraversal(BT->left);
        printf("%c", BT->data);
        InorderTraversal(BT->right);
    }
}

int main() {
    BinTreeNode *root = NULL;
    BinTreeNode *duplicateRoot = NULL;
    char data[Maxsize];
    int i = 0;

    printf("请输入节点：");
    while (i < Maxsize) {
        scanf("%s", &data[i]);
        if (data[i] == '#') {
            data[i] = data[i-1];
            break;
        }
        i++;
    }

    printf("构建二叉树\n");
    root = CreateBinTree(data, 1);
    printf("前序遍历：");
    PreOlder(root);
    printf("\n中序遍历：");
    InorderTraversal(root);
    printf("\n");
    duplicateRoot = BTreeCopy(root);
    printf("复制二叉树前序遍历：");
    PreOlder(duplicateRoot);
    printf("\n中序遍历：");
    InorderTraversal(duplicateRoot);
    printf("\n");

    return 0;
}
