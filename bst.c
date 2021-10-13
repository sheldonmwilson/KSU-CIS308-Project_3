/*
 * Name: Sheldon Wilson
 * Date: October 13, 2021
 * Assignment: Project 3 - BST implementation
 *
 * Description: This file contains the implementation of the functions necessary for the BST.
 */
#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

/*
 * Creates a new node with the given data.
 * In: data the node should contain
 * Out: a pointer to the node
 */
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

/*
 * Inserts the given key into the BST.
 * In: the root of the current BST and the key to insert
 * Out: the root of the updated BST
 */
Node* insert(Node* root, int key) {
    // If the node doesn't exist, create and return it.
    if (root == NULL) {
        return newNode(key);
    }
    // Recursive call on left child is key is smaller than root key
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    // Recursive call on right child if key is larger than root key
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    // Otherwise, key must already be in the root, so just return it
    return root;
}

/*
 * Searches the BST for the given key.
 * In: the root of the BST and the key to search for
 * Out: 1 if the key is found, 0 otherwise
 */
int search(Node* root, int key) {
    // Empty node, return 0
    if (root == NULL) {
        return 0;
    }
    // Key is in root, return 1 to indicate key found
    if (key == root->key) {
        return 1;
    }
    // Check left child with recursive call
    else if (key < root->key) {
        return search(root->left, key);
    }
    // Check right child with recursive call
    else if (key > root->key) {
        return search(root->right, key);
    }
    // Key not found, return 0
    return 0;
}

/*
 * Performs an inorder traversal of the BST and prints the keys to a string.
 * In: the root of the BST, a pointer to the string to print to, and the current index in the string
 * Out: the current index in the string to print to
 */
int inorder(Node* root, char* treeStr, int pos) {
    // Empty node, just return current position
    if (root == NULL) {
        return pos;
    }
    // Inorder traversal, updating position(index) in string as needed
    pos = inorder(root->left, treeStr, pos);
    pos += sprintf(treeStr + pos, "%d ", root->key);
    pos = inorder(root->right, treeStr, pos);
    return pos;
}

/*
 * Frees all memory in the BST.
 * In: the root of the BST to release
 */
void release(Node* root) {
    // Nothing left in BST, return from function
    if (root == NULL) {
        return;
    }
    // Postorder traversal with recursion to ensure all nodes are released
    release(root->left);
    release(root->right);
    free(root);
}
