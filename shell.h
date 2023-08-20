#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*FUNCTION PROTOTYPES*/
/*main.c*/
/*interactive and no_interactive mode functions*/
void interactive(void);
void no_interactive(void);

/* shell_interactive.c */
/*function to read the command input*/
char *read_cmd(void);
/*function to split the command input*/
char **split_cmd(char *line);
int execute_args(char **args);

/* execute_args */
int new_process(char **args);

/* shell_no_interactive */
/*function to read from file stream*/
char *read_file(void);

/*Builtin func*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);
#endif
