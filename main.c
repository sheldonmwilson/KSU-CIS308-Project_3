/*
 * Name: Sheldon Wilson
 * Date: October 13, 2021
 * Assignment: Project 3 - BST implementation
 *
 * Description: This file contains the main function, which calls functions from the included files
 * to create the desired program functionality.
 */
#include <stdlib.h>
#include "bst.h"
#include "io.h"

/*
 * Main function that creates the necessary variables for program operation, and then calls functions from
 * the other files to give the program the desired operation.
 */
int main() {
    Node* root = NULL;
    int value;
    int quit = 0;
    char command;
    char treeStr[100];

    while (!quit) {
        command = getCommand();
        switch (command) {
            case 'i':
                value = getValue(command);
                root = insert(root, value);
                break;
            case 's':
                value = getValue(command);
                printSearch(search(root, value), value);
                break;
            case 't':
                inorder(root, treeStr, 0);
                printInorder(treeStr);
                break;
            case 'q':
                quit = 1;
                release(root);
                break;
            default:
                break;
        }
    }
    return 0;
}
