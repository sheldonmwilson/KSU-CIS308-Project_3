/*
 * Name: Sheldon Wilson
 * Date: October 13, 2021
 * Assignment: Project 3 - BST implementation
 *
 * Description: The file contains the implementations of the input/output functions.
 */
#include <stdio.h>
#include "io.h"

/*
 * Prompts the user for a command.
 * Out: character representing user command
 */
char getCommand() {
    char c = ' ';
    printf("Enter (i)nsert, (s)earch, inorder (t)raversal, or (q)uit: ");
    scanf(" %c", &c);
    return c;
}

/*
 * Prompts the user for a value; prompt is dependent on command.
 * In: character representing the current command
 * Out: integer value input by user
 */
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

/*
 * Prints whether the value input by user is in the tree.
 * In: flag indicating if value is in the tree and the value
 */
void printSearch(int isInTree, int value) {
    if (isInTree) {
        printf("%d is in the tree.\n", value);
    }
    else {
        printf("%d is not in the tree.\n", value);
    }
}

/*
 * Prints the string storing an inorder traversal of the tree.
 * In: pointer to the string
 */
void printInorder(char* tree) {
    printf("%s\n", tree);
}
