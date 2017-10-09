#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command, int *argc, char*** argv)
{
	int num = 0;
	int num1 = 0;
	int i, j = 0;
	char ch;

	for (i = 0; i<strlen(command); i++) {
		ch = command[i];
		if (ch == ' ') {
			num++;
		}
	}
	num1 = num + 1;
	*argc = num1;
	printf("argc == %d \n", *argc);


	char* temp_command = (char *)malloc(sizeof(command));
	strncpy(temp_command, command, strlen(command));
	temp_command[strlen(command)] = '\0';
	printf("%s\n", temp_command);

	*argv = (char **)calloc(*argc, sizeof(char*)); // allocate space
	for (i = 0; i < *argc; i++) {
		(*argv)[i] = (char*)calloc(16, sizeof(char)); // allocate memory of each string
	}

	char *ptr = strtok(temp_command, " ");
	while (ptr != NULL)
	{
		for (j = 0; j<*argc; j++)
		{
			printf("=> %s\n", ptr);
			strncpy((*argv)[j], ptr, strlen(ptr));
			printf("argv=> %s\n", (*argv)[j]);
			//argv[j][strlen(ptr)] = '\0';
			ptr = strtok(NULL, " ");
		}

	}

}
