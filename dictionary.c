/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

struct trienode *newnode(void)
{
	struct trienode *ptr = NULL;

	ptr = (struct trienode *)calloc(1, sizeof(struct trienode));

	  ptr->isleaf = false;
    for (int i = 0; i < 27; i++)
      ptr->child[i] = NULL;

	return ptr;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
  tnode = root;
  for (int d = 0; word[d] != '\0'; d++)
  {
    int x = word[d];

    if (x >= 'A' && x <= 'Z')
      x += 32;

    if (x == 39)
      x = 0;

    else
      x -= 96;

    tnode = tnode->child[x];

    if (!tnode)
      return false;

    if (word[d+1] == '\0' && tnode->isleaf == false)
      return false;
  }
  return true;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
  int index;
  FILE *inptr = fopen(dictionary, "r");
  if (!inptr)
    return false;
  else
  {
    triecounter = 0;
		root = newnode();
		tnode = root;
    for (int c = fgetc(inptr); c != EOF; c = fgetc(inptr))
    {
      if (c >= 'A' && c <= 'Z')
        c += 32;

      if (c >= 'a' && c <= 'z')
      {
        index = c - 96;

        if (!tnode->child[index])
        {
          tnode->child[index] = newnode();
          tnode = tnode->child[index];
        }

        else
          tnode = tnode->child[index];
      }

      else if (c == 39)
      {
        if (!tnode->child[0])
        {
          tnode->child[0] = newnode();
          tnode = tnode->child[0];
        }

        else
          tnode = tnode->child[0];
      }

      else if (c == 10)
      {
        tnode->isleaf = true;
        tnode = root;
        triecounter++;
      }
    }
		fclose(inptr);
    return true;
  }
}



/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (*load)
      return triecounter;

    else
      return 0;
}

bool freetnode(struct trienode *temp)
  {
    for (int q = 0; q < 27; q++)
    {
      if (temp->child[q])
        freetnode(temp->child[q]);
    }
    free(temp);
    return true;
  }

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload()
{
  if (freetnode(root))
    return true;
  else
    return false;
}
