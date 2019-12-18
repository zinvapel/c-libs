/*
 * core.c
 *
 *  Created on: Dec 18, 2019
 *      Author: ruamtp3
 */

#include "core.h"
#include <stdlib.h>

void toLeaf(struct Node* node) { // change Node.isEnd field
    node->isEnd = true;
}

struct Node *insert(struct Node *node, char ch) { // Add ch as Node to parent
    if (node->branch) {
        struct Branch *branch = node->branch;

        do {
            if (branch->node->ch == ch) {
                return branch->node;
            }
        } while (branch->next && (branch = branch->next));

        struct Branch *nextBranch = createBranch(node, ch);
        branch->next = nextBranch;

        return nextBranch->node;
    } else {
        node->branch = createBranch(node, ch);

        return node->branch->node;
    }
}

struct Node *next(struct Node* node, char ch) { // Search child Node with char
    if (node->branch) {
        struct Branch *branch = node->branch;

        do {
            if (branch->node->ch == ch) {
                return branch->node;
            }
        } while ((branch = branch->next));
    }

    return NULL;
}

struct Node *createNode(char ch) { // Create new Node
    struct Node *node = malloc(sizeof(struct Node));

    node->ch = ch;
    node->isEnd = false;
    node->branch = NULL;

    return node;
}

struct Branch *createBranch(struct Node *node, char ch)
{
    struct Branch *branch = malloc(sizeof(struct Branch));
    branch->owner = node;
    branch->node = createNode(ch);
    branch->next = NULL;

    return branch;
}
