// Include header file
#include "tmcast.h"

// Main function
int main(int argc, const char *argv[])
{
  // Sanitize argument count
  if (argc < 1 || argc > MAX)
  {
    return 1; // Out of bounds error
  }
  
  // Sanitize argument array
  if (LEN(argv) != argc)
  {
    return 1; // Out of bounds error
  }
  for (i = 0; i < argc; i++) // Iterate over arguments
  {
    if (LEN(argv[i]) < 1 || LEN(argv[i]) > MAX) // Check length of each argument
    {
      return 1; // Out of bounds error
    }
  }
  
  for (i = 0; i < argc; i++)
  {
    // Parse flags
    if (argv[i][0] == '-')
    {
      // Identify flags
    }
    // Parse argument
    else
    {
      
    }
  }
  
  return 0;
}
