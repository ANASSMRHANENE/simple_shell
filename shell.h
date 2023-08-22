#ifndef SHELL_H
#define SHELL_H

<<<<<<< HEAD
/*LIBRARIES*/
=======
/*LIBRARY FUNCTIONS*/
>>>>>>> cb2b88385459e31241fb98ecefb2ed044cc958d1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

<<<<<<< HEAD
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
=======
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
>>>>>>> cb2b88385459e31241fb98ecefb2ed044cc958d1

/*execute_cmd*/
int builtins_num(void);
int exec_pid(char **agmts);

/*noninteractive_mode*/
/*function to read from file stream*/
char *read_file(void);

<<<<<<< HEAD
/*Builtin func*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);
=======
/*Builtin functions*/
int my_exit(char **agmts);
>>>>>>> cb2b88385459e31241fb98ecefb2ed044cc958d1
#endif
