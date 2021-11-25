// Include header file
#include "input.h"

// Builds the hash table for the flags
bool build_table(void)
{
    // Initialize table
    flagTupleNode *flagTable[UINT_MAX + 1];

    // Set flag names
    char *names[NUM_FLAGS] = {"version"};
    bool nodeResult = true;
    int a = 0;
    do
    {
        // Generate hash of word, condense within bounds
        unsigned int hash = super_fast_hash(names[a], strlen(names[a])) % UINT_MAX;
        
        // Write new node to table
        if (flagTable[hash] == NULL)
	{
		nodeResult = write_node(flagTable[hash], names[a]);
	}
	else
	{
		nodeResult = load_value(flagTable[hash], names[a]);
	}
        
        // Move to next name and check if finished
        a++;
        if (a == NUM_FLAGS)
        {
            return true;
        }
    } while (nodeResult == true);
    return false;
}

bool load_value(flagTupleNode* node, const char* insert)
{
    bool nodeResult;
    
    // If no next make new node
    if (node -> next == NULL)
    {
            nodeResult = write_node(node -> next, insert);
    }
    
    // Recursively follow linked list until null pointer is found
    else
    {
            nodeResult = load_value(node -> next, insert);
    }
    return nodeResult;
}

bool write_node(flagTupleNode* node, const char* insert)
{
    node = calloc(1, sizeof(flagTupleNode));
    
    // Check if memory allocation was successful
    if (node == NULL)
    {
        return false;
    }
    
    // Set variables for flag node tuple
    strcpy(node -> name, insert);
    node -> value = false;
    node -> next = NULL;
    return true;
}
