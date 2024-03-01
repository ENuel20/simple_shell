#include "main.h"

/**
 * read_command - reads the command into the line buffer
 * @line: pointer to the buffer that stores the buffer
 *
 * Description: fuction takes input from stdin and stores them
 * Return: -1 on failure , size_t of buff_size on success
 */

ssize_t read_command(char **line)
{
	size_t buffer_size = 0;

	return (getline(line, &buffer_size, stdin));
}
