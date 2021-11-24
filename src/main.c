// Include header file
#include "input.h"

// Define flag tuple hash table node
typedef struct flagTupleNode
{
    char name[50];
    bool value;
    struct flagTupleNode *next;
} flagTupleNode;

// Main function
int main(int argc, const char *argv[])
{
    // Sanitize argument count
    if (argc < 1 || argc > MAX)
    {
        printf("Too many arguments.\n");
        return 101;
    }

    // Sanitize argument array
    int count = 0;
    while(argv[++count] != NULL);
    if (count != argc)
    {
        printf("Out of bounds error.\n");
        return 100;
    }
    
    // Check for arguments
    if (argc < 2)
    {
        printf("No arguments.");
        return 200;
    }
    
    // Construct flag hash table
    flagTupleNode *flagTable[UINT_MAX + 1];
    flagTupleNode *flagTable[UINT_MAX + 1] = {NULL};
    bool build_result = build_table();
    if (build_result == false)
    {
        printf("Memory allocation error.\n");
        return 300;
    }
    
    // Iterate over arguments
    for (int i = 1; i < argc; i++)
    {
        count = 0;
	while(argv[i][++count] != '\0');
	    
	// Sanitize arguments
        if (count < 1 || count > MAX)
        {
            printf("Arguments too long.\n");
            return 102;
        }
        
        // Parse flags
        if (argv[i][0] == '-')
        {
            // Identify flags
            for (int j = 1; j < count; j++)
            {
                // Catch long form flags
                if (j == 1 && argv[i][j] == '-')
                {
                    // Detect long form flags
                    if (strcmp(argv[i], "--version") == 0)
                    {
                            // Set boolean of preset struct to true
		    }
                    
		    // Catch invalid flags 
		    else
		    {
                            printf("Invalid flag %s.\n", argv[i]);
                            return 201;
                    }
                }
                else
                {
                    // Detect short form flags
                    if (argv[i][j] == 'v')
                    {
                            // Set boolean of preset struct to true
                    }
                    
		    // Catch invalid flags
		    else
		    {
                            printf("Invalid flag -%c.\n", argv[i][j]);
                            return 201;
                    }
                }
            }
        }

        // Parse argument
        else
        {

        }
    }

    return 0; // Exit success
}
