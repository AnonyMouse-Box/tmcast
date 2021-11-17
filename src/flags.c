// Include header file
#include "flags.h"

// Builds the hash table for the flags
bool build_table(void)
{
    // Set flag names
    char *names[NUM_FLAGS] = {"version"};
    bool node_result = true;
    int a = 0;
    do
    {
        // Generate hash of word, condense within bounds
        unsigned int hash = super_fast_hash(names[a], strlen(names[a])) % UINT_MAX;
        
        // Write new node to table
        node_result = write_node(flagTable[hash]);
        
        // Move to next name and check if finished
        a++;
        if (a == NUM_FLAGS)
        {
            return true;
        }
    } while (node_result == true)
    return false;
}

bool write_node(flagTupleNode *ptrNode)
{
    // If no entry at hash, write flag to node
    if (ptrNode == NULL)
    {
        ptrNode = calloc(1, sizeof(flagTupleNode));
        
        // Check if memory allocation was successful
        if (ptrNode == NULL)
        {
            return false;
        }
        
        // Set variables for flag node tuple
        strcpy(ptrNode -> name, names[a]);
        ptrNode -> value = false;
        ptrNode -> next = NULL;
        return true;
    }
    
    // If entry exists, follow the pointer to next
    else
    {
        // Recursively follow linked list until null pointer is found
        bool ptrResult = write_node(ptrNode -> *next);
        return ptrResult;
    }
}
