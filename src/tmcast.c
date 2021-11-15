// Include header file
#include "tmcast.h"

// Main function
int main(int argc, const char *argv[])
{
  // Sanitize argument count
  if ( argc < 1 || argc > 10000 )
  {
    return 1; // Out of bounds error
  }
  
  // Sanitize argument array
  if ( LEN(argv) != argc )
  {
    return 1; // Out of bounds error
  }
  
  return 0;
}
