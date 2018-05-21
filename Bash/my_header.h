// Define STRUCTURES here
typedef struct hist
{
	char cmd[30];
	struct hist *next;
}HIST;


// Define GLOBAL VARIABLES

HIST *start;


void hist_stack(char *);
void hist_cmd();

void scanip();

// Define Header Files here

#include<time.h>
#include<utime.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<dirent.h>
#include<strings.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/resource.h>