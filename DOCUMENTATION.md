### Exit Codes

| Code   | Error Type      | Error                    | Meaning                                                                   |
| ------ | --------------- | ------------------------ | ------------------------------------------------------------------------- |
| 0      | Success.        | Success.                 | Exited successfully, program complete.                                    |
| 100    | Bounding error. | Out of bounds error.     | Number of arguments is not the same as count, unknown cause, fatal error. |
| 101    | Bounding error. | Too many arguments.      | Number of arguments is less than 1 or greater than 10k.                   |
| 200    | Syntax error.   | No arguments.            | No arguments given, tmcast requires arguments to run.                     |
| 201    | Syntax error.   | Invalid flas.            | Flag does not match any listed.                                           |
| 300    | Memory error.   | Memory allocation error. | Null pointers pulled when allocating memory, check memory.                |
