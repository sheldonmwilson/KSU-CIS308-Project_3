#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }
    n->key = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

int search(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (key == root->key) {
        return 1;
    }
    else if (key < root->key) {
        return search(root->left, key);
    }
    else if (key > root->key) {
        return search(root->right, key);
    }
    return 0;
}

int inorder(Node* root, char* treeStr, int pos) {
    if (root == NULL) {
        return pos;
    }
    pos = inorder(root->left, treeStr, pos);
    pos += sprintf(treeStr + pos, "%d ", root->key);
    pos = inorder(root->right, treeStr, pos);
    return pos;
}

void release(Node* root) {
    if (root == NULL) {
        return;
    }
    release(root->left);
    release(root->right);
    free(root);
}
