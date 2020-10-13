#include "functions.h"

int main(int argc, char *argv[])
{
    system("clear");                                                //clears compiler
	switch (fork())
	{
		case -1:
			perror("Fork");											//error for fork
			exit(2);

		case 0: /* in child */
			interMode();											//interactive mode
			exit(1);

		default: /* in parent */
			wait(NULL);												//wait for child to finish

	}
	return 0;
}