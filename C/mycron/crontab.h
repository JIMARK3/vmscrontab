#ifndef JI_CRONTAB_H
#define JI_CRONTAB_H

#include <time.h>
struct crontab_entry {
  char command[200];
  char minute[30];
  char hour[30];
  char day_of_month[30];
  char month[30];
  char day_of_week[30];
};

void get_entries_from_file();

void print_entries();

int matchtime(int current_time, char *min);

int time_check(struct crontab_entry entry);

int have_new_entrys();

#define SPOOL "/cloudide/workspace/C/spool/"
#define MARKNAME SPOOL"newentrys.mark"
#define CRONAREA "/cloudide/workspace/C/"//modify this into log name
#endif //JI_CRONTAB_H

