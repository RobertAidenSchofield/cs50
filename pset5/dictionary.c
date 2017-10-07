/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h" 

#define HASHTABLE_SIZE 65460


typedef struct node
{
    char word[LENGTH];
    struct node* next;
}
node;

node* hashtable[HASHTABLE_SIZE];

// global var for tracking dictionary size
unsigned int word_count = 0;

// global boolean
bool loaded = false;

int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}


bool check(const char* word)
{
    
    int len = strlen(word);
    char word_copy[len + 1];
    
    // convert word to lowercase 
    for (int i = 0; i < len; i++)
    {
      word_copy[i] = tolower(word[i]);
    }
    
    word_copy[len] = '\0';
    
    // get hash value
    int h = hash_it(word_copy);
    
    // assign cursor node to the first node
    node* cursor = hashtable[h];
    
    // check until the end of the linked list
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        else
        {
            // check next node
            cursor = cursor->next;
        }
    }
    return false;
}


bool load(const char* dictionary)
{
   
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
    
    // open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }
      
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;
        
        if (feof(fp))
        {
            // end of file
            free(new_node);
            break;
        }

        word_count++;
        
       
        int h = hash_it(new_node->word);
        node* head = hashtable[h];
        
       
        if (head == NULL)
        {
            hashtable[h] = new_node;
        }
        
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    // close dictionary
    fclose(fp);
    loaded = true;
    return true;
}


unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}


bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            // maintain connection to linked list 
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}