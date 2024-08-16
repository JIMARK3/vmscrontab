#include "../mycron/crontab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cron_load(char *cron_file);
int cron_show();
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <cron_file>\n", argv[0]);
    return 1;
  }
  char *command = argv[1];
  printf("command: %s\n", command);
  if (strcmp(command, "-l") == 0) {
    int ret = cron_show();
    return ret;
  }
  char *cron_file = command;
  printf("cron_file: %s\n", cron_file);

  int ret = cron_load(cron_file);
  return ret;
}
int cron_load(char *cron_file) {

  FILE *fp = fopen(cron_file, "r");
  if (fp == NULL) {
    printf("Failed to open cron file: %s\n", cron_file);
    return 1;
  }
  FILE *tab = fopen(SPOOL "crontab", "w");
  if (tab == NULL) {
    printf("Failed to open tab file: %s\n", cron_file);
    return 1;
  }
  struct crontab_entry crontab;
  char line[500];
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (*line == '#' || *line == '\n') {
      continue;
    }
    char *find = strchr(line, '\n');
    if (find)*find = '\0';
    int i = sscanf(line, "%s %s %s %s %s %200c", crontab.minute, crontab.hour,
                   crontab.day_of_month, crontab.month, crontab.day_of_week,
                   crontab.command);
    if (i != 6) {
      printf("Failed to parse line: %s\n", line);
      continue;
    };
    fprintf(tab, "%s %s %s %s %s %s\n", crontab.minute, crontab.hour,
            crontab.day_of_month, crontab.month, crontab.day_of_week,
            crontab.command);
  }
  fclose(fp);
  fclose(tab);

  FILE *markfile = fopen(MARKNAME, "w");
  if (markfile == NULL) {
    printf("Failed to create markfile: %s\n", MARKNAME);
    return 1;
  }
  fclose(markfile);
  return 0;
}
int cron_show() {
  FILE *fp = fopen(SPOOL "crontab", "r");
  if (fp == NULL) {
    printf("Failed to open tab file: %s\n", SPOOL "crontab");
    return 1;
  }
  char line[500];

  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
  }
  fclose(fp);
  return 0;
}