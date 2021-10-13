/*
 * Name: Sheldon Wilson
 * Date: October 13, 2021
 * Assignment: Project 3 - BST implementation
 *
 * Description: The file contains the prototypes for the input/output functions.
 */
#ifndef IO_H
#define IO_H

/* Prototypes */
char getCommand();
int getValue(char command);
void printSearch(int isInTree, int value);
void printInorder(char* tree);

#endif //IO_H
