#include "utils.h"
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
    *argv  = (char**)malloc(sizeof(*argv)*256);
    *argc = 0;
    char *tmp;

    tmp = strtok(strdup(command), " \t\n"); 

	if(tmp == NULL){
	*argc = 1;
	**argv = malloc(10);
	strcpy((**argv),"");
	(*argv)++;
	}

    while(tmp!=NULL)
    {
        **argv = malloc(strlen(tmp) + 1);
        strcpy(**argv,tmp);
        (*argv)++;
        (*argc)++;
        tmp = strtok(NULL, " \t\n");
    }
    

    *argv -= (*argc);
    *argv = (char**)realloc(*argv, sizeof(*argv)*(*argc));
}
