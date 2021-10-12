#include <stdio.h>
#include "io.h"

char getCommand() {
    char c = ' ';
    printf("Enter (i)nsert, (s)earch, inorder (t)raversal, or (q)uit: ");
    scanf(" %c", &c);
    return c;
}

int getValue(char command) {
    int i;
    if (command == 'i') {
        printf("Enter a number to insert: ");
    }
    else {
        printf("Enter a number to search for: ");
    }
    scanf("%d", &i);
    return i;
}

void printSearch(int isInTree, int value) {
    if (isInTree) {
        printf("%d is in the tree.\n", value);
    }
    else {
        printf("%d is not in the tree.\n", value);
    }
}

void printInorder(char* tree) {
    printf("%s\n", tree);
}
