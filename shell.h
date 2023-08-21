#ifndef SHELL_H
#define SHELL_H

/*LIBRARY FUNCTIONS*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*MACROS*/
#define TKN_DELIMITER " \n\t\r\a\""
extern char **environ;

/*FUNCTION PROTOTYPES*/
/* main.c */
/*interactive and noninteractive mode functions*/
void interactive_mode(void);
void noninteractive_mode(void);

/* shell.c */
/*interactive mode function to read user input*/
char *read_cmd(void);
/*function to split input string*/
char **split_cmd(char *in_str);
int execute_cmd(char **agmts);

/*execute_cmd*/
int builtins_num(void);
int exec_pid(char **agmts);

/*noninteractive_mode*/
/*function to read from file stream*/
char *read_file(void);

/*Builtin functions*/
int my_exit(char **agmts);
#endif
