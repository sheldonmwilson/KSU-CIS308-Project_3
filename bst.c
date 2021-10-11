#include <stdlib.h>
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

Node* insert(Node* n, int key) {
    if (n == NULL) {
        return newNode(key);
    }
    if (key < n->key) {
        n->left = insert(n->left, key);
    }
    else {
        n->right = insert(n->right, key);
    }
    return n;
}

Node* search(Node* root, int key) {
    //If tree is empty, or if key is at the root
    if (root == NULL || root->key == key) {
        return root;
    }
    //Check if key is greater than root's key
    if (key > root->key) {
        return search(root->right, key);
    }
        //Otherwise, the key is less than the root's key
    else {
        return search(root->left, key);
    }
}

Node* minValueNode(Node* n) {
    Node* current = n;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* delete(Node *root, int key) {
    //Check if tree is empty
    if (root == NULL) {
        return root;
    }

    //Find the node to delete
    if (key < root->key) {
        root->left = delete(root->left, key);
    }
    else if (key > root->key) {
        root->right = delete(root->right, key);
    }
    else {
        //Check if the node has one or no children
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        //If the node has two children
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}
