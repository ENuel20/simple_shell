#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;
	char *args[2];

	while (1)
	{
		printf("$ ");
		read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (read_bytes == 0)
		{
			printf("\n");
			break;
		}
		else if (read_bytes == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else
		{
			buffer[read_bytes - 1] = '\0';
			args[0] = buffer;
			args[1] = NULL;

			if (fork() == 0)
			{
				if (execve(buffer, args, environ) == -1)
				{
					perror(buffer);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
			}
		}
	}
	return (0);
}
