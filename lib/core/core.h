/*
 * core.h
 *
 *  Created on: Dec 18, 2019
 *      Author: zinvapel
 */

#ifndef LIB_CORE_CORE_H_
#define LIB_CORE_CORE_H_

#include <stdio.h>
#include <stdbool.h>

struct Node {
    char ch;
    bool isEnd;
    struct Branch *branch;
};

struct Branch {
    struct Node *owner;
    struct Node *node;
    struct Branch *next;
};

// Method list
void toLeaf(struct Node*); // change Node.isEnd field
struct Node *insert(struct Node*, char); // Add char as Node to parent
struct Node *next(struct Node*, char); // Search child Node with char

// Factory
struct Node *createNode(char); // Create new Node
struct Branch *createBranch(struct Node*, char);

#endif /* LIB_CORE_CORE_H_ */
