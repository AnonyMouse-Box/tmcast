// Include header file
#include "flags.h"

// Builds the hash table for the flags
bool build_table()
{
    // Set flag names
    char *names[NUM_FLAGS] = {"version"};
    bool pointer_result = true;
    int a = 0;
    do
    {
        // Generate hash of word, condense within bounds
        unsigned int hash = superFastHash(names[a], strlen(names[a])) % UINT_MAX;
        
        // If no entry at hash, write flag to node
        if (flagTable[hash] == NULL)
        {
            flagTable[hash] = calloc(1, sizeof(flagTupleNode));
            
            // Check if memory allocation was successful
            if (flagTable[hash] != NULL)
            {
                pointer_result = false;
                break;
            }
            
            // Set variables for flag node tuple
            strcpy(flagTable[hash] -> name, names[a]);
            flagTable[hash] -> value = false;
        }
        
        // If entry exists, follow the pointer to next
        else
        {
            // Recursively follow linked list until null pointer is found
        }
        
        // Move to next name and check if finished
        a++;
        if (a == NUM_FLAGS)
        {
            return true;
        }
    } while (pointer_result == true)
    return false;
}
