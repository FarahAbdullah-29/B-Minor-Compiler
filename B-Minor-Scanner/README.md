## Farah Abdullah

## Overall Notes
Files Created:
1) tokens.h: This file contain is an enum file that contains the constants that we were provided with. This grouping of enums would later be used in the util.c file which was created next. 
2) utils.c: This file uses the tokens in the tokens.h file and implements a switch statement. This approach allowed it to be possible to check if the token in the parameters matches any of the ones we had.
3) test-scanner.c: This file is responsible for iterating through the tokens and matching their given values to their names. A while loop was implemeneted to ensure that as long as token = yylex(), we would continue to try and match a token to its correct name. 
