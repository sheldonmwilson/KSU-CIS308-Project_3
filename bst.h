#ifndef BST_H
#define BST_H

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data);
Node* insert(Node*, int);
Node* search(Node*, int);
Node* delete(Node*, int);


#endif //BST_H
