#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../mycron/crontab.h"
int main(){
time_t t;
//get current time
time(&t);
printf("Current time: %s", ctime(&t));
long int ct = (unsigned long int)t;
char s[128];
sprintf(s, "%ld", ct);
char filename [128];
//file_dir_path = /cloudide/workspace/C/test_dir
strcpy(filename, "/cloudide/workspace/C/test_dir/");
strcat(filename, s);
//join ff.dat into filename
strcat(filename, "ff.dat");
FILE * file = fopen(filename, "w");
fprintf(file, "Hello World");
fclose(file);


}