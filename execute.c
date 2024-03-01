#include "main.h"

/**
 * execute_command - this functions execute commands
 * @command: this is the command
 *
 * Description: collects command from stdin and excutes the first string passed
 */

void execute_command(char *command)
{
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	if (execve(command, args, environ) == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
}
