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

void _puts(char *str);
void excom(char **argv);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void perror(const char *s);
int _putchar(char c);
char *strtok(char *str, const char *del);
char mymsg(char *input);
char *custom_env(char *name);
int _strcmp(const char *s1, const char *s2);
char *getmy_loc(char *mycommand);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int stat(const char *pathname, struct stat *statbuf);
extern char **environ;
int _strncmp(const char *s1, const char *s2, size_t num);
pid_t getpid(void);
void exit(int status);
void myenv(void);
int main(int ac, char **av);


#endif
