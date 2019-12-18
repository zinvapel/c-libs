/*
 * trie.h
 *
 *  Created on: Dec 18, 2019
 *      Author: ruamtp3
 */

#ifndef LIB_TRIE_H_
#define LIB_TRIE_H_

#include <stdbool.h>
#include "core/core.h"

struct Node *buildIndex(char*);
bool contains(struct Node*, char*);

#endif /* LIB_TRIE_H_ */
