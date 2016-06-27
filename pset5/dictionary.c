/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node* next[27];
}
node;

// Global first node (empty node).
node* root;

//Counter for number of words in the dictionary.
int n_dict = 0;

// Define the deallocate function prototype
void deallocate(node* trie_pointer);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    if (root == NULL)
    {
        printf("ERROR: Dictionary has not been properly loaded.\n");
        return false;
    }
    
    node* current = root;
    
    for (int i = 0; i < strlen(word); i++)
    {
        int c = tolower(word[i]);
        
        if (c == '\'')
        {
            c = 26;
        }
        else if (c >= 'a' || c <= 'z')
        {
            c = c-'a';
        }
        
        if (current->next[c] == NULL)
        {
            return false;
        }
        else
        {
            current = current->next[c];
        }
    }
    
    if (current->is_word)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = malloc(sizeof(node));
    
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Couldn't open file.\n");
        return false;
    }
    else
    {
        node* current = root;
        for (int c = fgetc(dict); c != EOF; c = fgetc(dict))
        {
            if (isalpha(c) || c == '\'')
            {
                // Setting c, so it can be used for array index.
                if (c == '\'')
                {
                    c = 26;
                }
                else
                {
                    c = c-'a';
                }
                
                if (current->next[c] == NULL) {
                    current->next[c] = malloc(sizeof(node));
                }
                
                current = current->next[c];
            }
            else if (c == '\n')
            {
                //Indicating end of a word.
                current->is_word = true;
                //Resetting the node for new word.
                current = root;
                n_dict++;
            }
        }
        
        fclose(dict);
        return true;
    }
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return n_dict;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    deallocate(root);
    return true;
}

void deallocate(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < 27; i++)
    {
        if (root->next[i] != NULL)
        {
            deallocate(root->next[i]);
        }
    }
    free(root);
}