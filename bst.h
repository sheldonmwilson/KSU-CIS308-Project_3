/*
 * Name: Sheldon Wilson
 * Date: October 13, 2021
 * Assignment: Project 3 - BST implementation
 *
 * Description: This file contains the implementation of a node structure and the prototypes for the BST
 * functions.
 */
#ifndef BST_H
#define BST_H

/*
 * Definition of the node structure for the BST.
 */
typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
} Node;

/* Prototypes */
Node* insert(Node* root, int key);
int search(Node* root, int key);
int inorder(Node* root, char* treeStr, int pos);
void release(Node* root);

#endif //BST_H
