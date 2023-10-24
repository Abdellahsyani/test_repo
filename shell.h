#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


int main(int ac, char **argv);
char **splitazer(char *line);
int execute(char **cmd, char **argv, int num);
char *read_line(void);
char *shows_path(char *path);
char *handle_path(char *mycom);
void error_one(char *ism, char *cmd, int num);
/*builtin*/
int _binaya_ton(char *cmd);
void _bin_handlon(char **cmd, char **argv, int *stat, int num);
void _quit_pro(char **cmd, int *stat);
void _environ_write(char **cmd, int *stat);
/*all suport function*/
void rev_str(char *str, int len);
char *_itoa(int n);
int _strncmp(const char *S1, const char *S2, size_t num);
void free2D(char **arr);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
extern char **environ;


#endif
