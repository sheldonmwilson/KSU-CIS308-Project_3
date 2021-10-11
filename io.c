#include <stdio.h>
#include "io.h"

char getOption() {
    char c;
    printf("Enter (i)nsert, (s)earch, inorder (t)raveral, or (q)uit: ");
    scanf("%c", &c);
    return c;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}