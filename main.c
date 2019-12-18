#include <stdio.h>

#include "lib/trie.h"

struct Node *buildIndex(char *text);

int main(int argc, const char *argv[])
{
    char *text = "halo halcium hahn hell hello help";
    struct Node *index = buildIndex(text);

    printf("`help` in text: %d\n", contains(index, "help"));
    printf("`hahn` in text: %d\n", contains(index, "hahn"));
    printf("`hepl` in text: %d\n", contains(index, "hepl"));

    return 0;
}
