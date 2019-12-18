/*
 * trie.c
 *
 *  Created on: Dec 18, 2019
 *      Author: zinvapel
 */

#include "trie.h"

struct Node *buildIndex(char *text) {
	struct Node *node = createNode('\0');
	struct Node *root = node;

	for (char *ch = text; *ch != '\0'; ch++) {
		if (*ch != ' ') {
			node = insert(node, *ch);

			continue;
		}

		toLeaf(node);
		node = root;
	}

	return root;
}

bool contains(struct Node *index, char *text)
{
	struct Node *node = index;

	for (char *ch = text; *ch != '\0'; ch++) {
		node = next(node, *ch);

		if (!node) {
			return false;
		}
	}

	return true;
}
