#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/
/* main.c */
void interactive(void); // instead of shell_interactive
void no_interactive(void); // instead of shell_no_interactive

/* shell_interactive.c */
char *read_cmd(void); //instead of read_line
char **split_cmd(char *line); // instead of split_line
int execute_args(char **args);

/* execute_args */
int new_process(char **args);

/* shell_no_interactive */
char *read_file(void); //instead of read_stream

/*---Builtin func---*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);
#endif
