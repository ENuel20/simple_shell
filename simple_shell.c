#include "main.h"

/*
 * Main: - Entry point of the simple shell program
 *
 * Description: This program implements a simple shell that reads
 *              commands from the user, executes them using execve,
 *              and waits for the command to complete.
 *
 * Return: 0 on successful execution, or exit(EXIT_FAILURE) on failure.
 */

int main(void)
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t read_bytes;
	char *args[2];

	while (1)
	{
		printf("$ ");
		read_bytes = getline(&line, &buffer_size, stdin);
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
			args[0] = line;
			args[1] = NULL;
			if (fork() == 0)
			{
				if (execve(line, args, environ) == -1)
				{
					perror(line);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
			}
		}
	}
	free(line);
	return (0);
}

