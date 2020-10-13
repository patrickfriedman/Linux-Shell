#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void interMode();
//void batchMode();

void bash2(char command[]);
void CD(char path[]);