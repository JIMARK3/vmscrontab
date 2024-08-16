#include "crontab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
extern struct crontab_entry entries[100];
extern int num_entries;
void get_entries_from_file() {
  char *crontab_file = SPOOL "crontab";
  FILE *file = fopen(crontab_file, "r");
  if (file == NULL) {
    printf("Failed to open file: %s\n", crontab_file);
    exit(1);
  }
  // read file line by line
  // read one line
  num_entries = 0;
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    if (*line == '#' || *line == '\n') {
      continue;
    }
    char *find = strchr(line, '\n');
    if (find)*find = '\0';
    int i = 0;
    // use sscanf() read 6 elements from line %s %s %s %s %s char [200]
    int e = sscanf(line, "%s %s %s %s %s %200c", entries[num_entries].minute,
                   entries[num_entries].hour, entries[num_entries].day_of_month,
                   entries[num_entries].month, entries[num_entries].day_of_week,
                   entries[num_entries].command);
    if (e != 6) {
      printf("Failed to parse line: %s\n", line);
      continue;
    } else {
      printf("Successfully parsed line: %s\n", line);
      num_entries++;
    }
  }
}

void print_entries() {
  for (int i = 0; i < num_entries; i++) {
    printf("%s %s %s %s %s %s\n", entries[i].minute, entries[i].hour,
           entries[i].day_of_month, entries[i].month, entries[i].day_of_week,
           entries[i].command);
  }
}