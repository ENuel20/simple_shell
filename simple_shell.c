#include "main.h"

/**
 * simple_shell - function performs like a command line interpreter.
 * Description: it reads command from stdin and executes it, freees up the
 *
 * Return: 0 on success
 */

void simple_shell(void)
{
	char *line = NULL;
	ssize_t read_bytes;
	int status;

	while (1)
	{
		printf("$ ");
		read_bytes = read_command(&line);
		if (read_bytes == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		else if (read_bytes == 0)
		{
			printf("\n");
			break;
		}
		else
		{
			if (line[read_bytes - 1] == '\n')
			{
				line[read_bytes - 1] = '\0';
			}
			if (fork() == 0)
			{
				execute_command(line);
			}
				else
				{
					wait(&status);
				}
			}
		}
		free(line);
}

