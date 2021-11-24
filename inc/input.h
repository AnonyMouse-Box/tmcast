// Included libraries
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

// Local files
#include "hash.h"

// Definitions
#define MAX 10000                       // Set upper bound
#define NUM_FLAGS 1                     // Set number of flags

// Define flag tuple hash table node
typedef struct flagTupleNode
{
    char name[50];
    bool value;
    struct flagTupleNode *next;
} flagTupleNode;

flagTupleNode *flagTable[UINT_MAX + 1];

// Function prototypes
int main(int argc, const char *argv[]);
bool build_table(void);
bool write_node(flagTupleNode *ptrNode);
