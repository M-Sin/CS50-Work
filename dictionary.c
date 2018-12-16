// Implements a dictionary's functionalit
// Helper program that performs various functions for a spellchecker program from Harvard University CS50 course problem se
// Requires dictionary.h file and custom CS50 course ctype.h along with standard librarie


#include <stdbool.h
#include <stdio.h
#include <stdlib.h
#include <string.h
#include "dictionary.h
#include <ctype.h


// initialize variable
#define TABLESIZE 5
int wordcount=0


// hash array that stores nodes (0 to 53
// nodes are structs that contain a word (string of characters) and a pointer to the next nod
node *hashtable[TABLESIZE]


// hashing function determines and returns hash code (integer from 0 to 53) based on first two letters of input word (string of characters
int hash (const char *word

    // index will divide hash table into 2 (54/2 = 27 -> starting at hashtable[0] to hashtable[25], hashtable[26] to hashtable[53] is the second half
    // the first letter of the input world (word[0]) sorts the word from hash[0] to hash[25] (a to z
    // if the second letter is a-n, the hash remains in the first half of the tabl
    // if the second letter is m-z, the hash gets pushed to the second half of the tabl
    // this is done to balance speed of using the hash table versus memory usag
    // note that sorting is not case sensitiv
    int index = 0
    if (tolower(word[1])>110
       index=26
    return (((tolower(word[0])-97)+ index)%(TABLESIZE));      // return hash bucket number sorted by first letter of word // %TABLESIZE to keep within bounds of arra





// Returns true if word is in dictionary else fals
bool check(const char *word

    char temp[strlen(word)+1]
    for (int i=0;i!=strlen(word);i++
        temp[i] = tolower(word[i]);                 // convert word to lower cas
    temp[strlen(word)]='\0'
    node *chk = hashtable[hash(temp)];              // pointer that sorts input word into hashtable, points to what hashtable bucket points to (first node
    while (chk!=NULL)                               // while not at end of hash bucket connected nodes (last node points to null
    
        if (strncmp(chk->word,temp,LENGTH+1)==0)    // check if equal to wor
            return true
        chk = chk->next;                            // if not equal move pointer to next node that current node points t
    
    return false



// Loads dictionary into memory, returning true if successful else fals
// takes input parameter of a text file containing all the words in the loaded dictionar
bool load(const char *dictionary

    // open input file from const char pointe
    FILE *inptr = fopen(dictionary,"r")
    // return 1 if erro
    if (inptr == NULL
            return 1
    // create temp array for storing word from dictionar
    char temp[LENGTH+1]
    // set up the temp nod
    node *newnode = NULL
    // read strings of words from dictionar
    while(fscanf(inptr,"%s",temp)!=EOF)                     // read word into temp char array until EO
    
        newnode = malloc(sizeof(node));                     // create memory for new nod
        // error chec
        if (newnode == NULL
        
            fclose(inptr)
            printf("Memory error!")
            return false
        
        strcpy(newnode->word,temp);                         // put word into new nod
        newnode->next = hashtable[hash(temp)];              // point new node at whatever appropriate hashtable[i] is pointing at (which is pointing at previous node
        hashtable[hash(temp)] = newnode;                    // point hashtable [i] at the new first node in linked lis
        wordcount++;                                        // count how many nodes are put into hashtabl
    
    fclose(inptr)
    return true



// Returns number of words in dictionary if loaded else 0 if not yet loade
unsigned int size(void

    return (unsigned int)wordcount



// Unloads dictionary from memory, returning true if successfu
bool unload(void

    int i =0
    while(i<TABLESIZE)              // iterate over hashtabl
    
        node *freeup = hashtable[i];// point to hash bucket i, which points to first node of bucke
        while(freeup != NULL)       // iterate over nodes in each hash bucke
        
            node *temp = freeup;    // store current node address in tem
            freeup = temp->next;    // point freeup at next nod
            free(temp);             // free up node stored in addres
        
        i++
    
    return true

