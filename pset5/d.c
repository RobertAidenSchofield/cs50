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

#define HASHTABLE_SIZE 50000



/**
 * Returns true if word is in dictionary else false.
 */
 typedef struct node
 {
     char word[LENGTH + 1];
     struct node* next;
 }
 node;
 
 // pointer to nodes
 node * Hashtable[HASHTABLE_SIZE];
 
 // tracks dictionary size 
 int count = 0;
 
 bool didLoad = false; 
 
 // hash funtion 
 int hash_it(char* needs_hashing)
 {
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
 }




bool check(const char* word)
{
   
    int len= strlen(word);
    char word_copy[len + 1];
    
    // convert word to lowercase and store it in word_copy
    for (int i = 0; i < len; i++)
    {
       word_copy[i] = tolower(word[i]);
    }
    
    // add null terminator to end of char array
    word_copy[len] = '\0';
    
    // get hash value
    int h = hash_it(word_copy);
    
    // assign cursor node to the first node
    node* cursor = Hashtable[h];
    
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

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{   
    FILE* file = fopen("large", "r");
    if (file == NULL)
    {
        fclose(file); 
        printf("unable to open dictonary \n");
        return 1;
    }
    return false;
    
    // malloc space 
    node * new_node = malloc(sizeof(node));
    if (new_node== NULL)
    {
        printf("could not malloc new node.\n");
        return false;
    }
    
    fscanf(file,"%s", new_node-> word);
    new_node-> next = NULL;
    //increase dictionarty size 
    count++;
    
    int h = hash_it(new_node->word);
    node* head = Hashtable[h];
        
    // if empty, insert the first node
    if (head == NULL)
    {
        Hashtable[h] = new_node;
    } 
    //unsorted linked list to minimize load time 
    else
      {
        new_node->next = Hashtable[h];
        Hashtable[h] = new_node;
      }
    
    didLoad = true;
    fclose(file);
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(didLoad == true)
    {
        return count;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{ 
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* cursor = Hashtable[i];
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    didLoad = false;
    return true;
}