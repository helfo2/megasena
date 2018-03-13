#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Function: remove_dates_parenthesis
// Does: takes out every garbage data present in the pure file
// Parameters: [0] -> dirty string
// 			   [1] -> clean string (adress to add the clen string)
// Return: void

void remove_dates_parenthesis(char*[], char*[]);

// Function: fix_text
// Does: calls all functions to fix the file with garbage info
// Parameters: [0] -> output file for the correct data
// 			   [1] -> dirty string 
//			   [2] -> clean string (adress to add the clen string)
// Return: void
void fix_text(FILE**, char*[], char*[]);