#ifndef BST_H
#define BST_H

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int key);
int search(Node* root, int key);
int inorder(Node* root, char* treeStr, int pos);
void release(Node* root);

#endif //BST_H
