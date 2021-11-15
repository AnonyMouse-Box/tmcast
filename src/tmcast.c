// Include header file
#include "tmcast.h"

// Main function
int main(int argc, const char *argv[])
{
    // Sanitize argument count
    if (argc < 1 || argc > MAX)
    {
        printf("Too many arguments.\n");
        return 101; // Out of bounds error
    }

    // Sanitize argument array
    int count = 0;
    while(argv[++count] != NULL);
    if (count != argc)
    {
        printf("Out of bounds error.\n");
        return 100;
    }

    // Iterate over arguments
    for (i = 1; i < argc; i++)
    {
        // Sanitize arguments
        if (LEN(argv[i]) < 1 || LEN(argv[i]) > MAX)
        {
            printf("Arguments too long.\n");
            return 102;
        }

        // Parse flags
        if (argv[i][0] == '-')
        {
            // Identify flags
            for (j=1; j < LEN(arg[j]); j++)
            {
                // Catch long form flags
                if (j == 2 && argv[i][j] == '-')
                {
                    // Set long form boolean
                    break;
                }
                else
                {
                    // Detect short form flags
                    switch (argv[i][j])
                    {
                        case v:
                            // Set boolean of preset struct to true
                            break;

                        // Catch invalid flags
                        default:
                            printf("Invalid flags.\n");
                            return 200;
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
