/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

struct trienode
  {
    bool isleaf;
    struct trienode *child[27];
  };



char word[LENGTH];
struct trienode *root;
struct trienode *tnode;
struct trienode *temp;
int triecounter;



struct trienode *newnode();

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

 /**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool freetnode(struct trienode *temp);

bool unload(void);

#endif // DICTIONARY_H
