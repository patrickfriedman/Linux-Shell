#include "functions.h"

void interMode()
{
    char command[128], temp[128];                                   //cstring holding the command from user
    char *ptr[128];                                                 //evecvp ptr
    int i = 0;                                                      //counter

    while(1)                                                        //loop program continuously
    {
        printf("\nmajor2> ");                                       //propt the command line
        fgets(command, sizeof(command), stdin);                     //gets whole command
        strtok(command, "\n");                                      //removes endline token
        strcpy(temp, command);

        if (fork() == 0)                                            //forks to create child process
        {
            ptr[0] = strtok(command , " ");                         //gets additional arguments
            while (ptr[i] != NULL)
            {
                ptr[++i] = strtok(NULL, " ");                       //removes whitespace
            }
            execvp(ptr[0], ptr);                                    //executes bash commands

            if (strncmp(command, "cd", 2) == 0)                     //cd command
            {
                CD(temp);
            }
            else if(strncmp(command, "myhistory", 9) == 0)          //myhistory command
            {
            
            }
            else if(strncmp(command, "exit", 4) == 0)               //exit command
            {
            
            }
            else if(strncmp(command, "path", 4) == 0)               //path command
            {
            
            }
            else if(strncmp(command, "bash2", 5) == 0)               //bash2 command
            {
                bash2(temp);
            }
            else
            {
                printf("%s: command not found.\n", command);        //prompt if command fails
            }
        }
        else                                                        //parent process
        {
            wait(NULL);                                             //tells parent process to wait for child process
        }
    }
}