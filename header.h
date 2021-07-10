#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<sys/types.h>
#include<fcntl.h>
#include<limits.h>
#include<errno.h>
#include<signal.h>
#include <sys/wait.h>

extern void echo(char *sou);
extern void cd(char *sou);
extern void prompt();
extern void pwd(char *q);
extern void  ls(char *sou);
extern void pinfo(char *sou);
extern void bag(char *sou);
extern void bonus(int verifycount);
extern void spec4(char* temp);
extern void iodirec(char* string);
int bagcount;
int maincount;
int a[10000];
char *b[10000];
int stop[10000];
int direccount;
char *direclist[1000];
int cpid;
int cpids;