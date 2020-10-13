#include "functions.h"
void getpath(char path[]);

void CD(char path[])
{   
    if(strncmp(path, "cd ", 3) == 0)                    //checks if more arguments
    {
        getpath(path);                                  //chdir to path
    }
    else if (strncmp(path, "cd", 2) == 0)               //check if just cd
    {
        printf("Home:%s\n\n", path);
        chdir(getenv("HOME"));                          //chdir to home
        printf("%s\n", getcwd(path, 128)); 
    }
}

void getpath(char path[])
{
    path += 3;                                          //skips first 3 char
    if(chdir(path) == -1)
    {
        printf("Error\n");                              //error
    }
    
    printf("%s\n\n", path);
    chdir(path);                                        //chdir to path
    printf("%s\n", getcwd(path, 128)); 
}