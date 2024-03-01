#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute_command(char *command);
void simple_shell(void);
ssize_t read_command(char **line);
extern char **environ;

#endif
