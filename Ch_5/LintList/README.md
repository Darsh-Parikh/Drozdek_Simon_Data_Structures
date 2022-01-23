Write a rudimentary lint program to check whether all variables have been 
initialized and whether local variables have the same names as global variables.
Create a linked list of global variables and for each function create a linked 
list of local variables. In both lists store information on the first 
initialization of each variables and check if an initializeation has been made
before a variable is being used for the first time. Also, compare both lists to 
detect possible matches and issue a warning if a match is found. The list of 
local varaibles is freed after processing of one function is finished and 
created anew when a new function is encountered. Consider the possibility of 
maintaining an alphabetical order on both lists.

NOTE: This program also requires an empty `obj` directory, where all the object
files will be put. Github naturally deletes empty folders and so it becomes the 
responsibility of the user to create one.
