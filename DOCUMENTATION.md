### Exit Codes

| Code   | Error Type      | Error                | Meaning                                                                   |
| ------ | --------------- | -------------------- | ------------------------------------------------------------------------- |
| 0      | Success.        | Success.             | Exited successfully, program complete.                                    |
| ------ | --------------- | -------------------- | ------------------------------------------------------------------------- |
| 100    | Bounding error. | Out of bounds error. | Number of arguments is not the same as count, unknown cause, fatal error. |
| 101    | Bounding error. | Too many arguments.  | Number of arguments is less than 1 or greater than 10k.                   |
| 102    | Bounding error. | Arguments too long.  | Length of one or more arguments less than 1 or greater than 10k.          |
| ------ | --------------- | -------------------- | ------------------------------------------------------------------------- |
| 200    | Syntax error.   | Invalid flags.       | Flags do not match any listed.                                            |
