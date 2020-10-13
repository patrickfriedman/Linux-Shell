#include "functions.h"

void bash2(char command[])
{
    FILE *fp;
    char ch;

    command += 6;
    fp = fopen(command, "r");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
 
    printf("The contents of %s file are:\n\n", command);
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
}