#include <stdlib.h>
#include "bst.h"
#include "io.h"

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
                break;
            default:
                break;
        }
    }
    release(root);
    return 0;
}
