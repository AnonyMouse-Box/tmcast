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

// Function prototypes
int main(int argc, const char *argv[]);
bool build_table(void);
bool write_node(flagTupleNode *ptrNode);
