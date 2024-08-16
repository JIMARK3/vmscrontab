#include "crontab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
struct crontab_entry entries[100];
time_t now;
int num_entries = 0;

int main() {
  // chdir(CRONAREA);
  get_entries_from_file();
  print_entries();
  while (1) {
    if(have_new_entrys()){
      get_entries_from_file();
    }
    now = time(NULL);
    for (int i = 0; i < num_entries; i++) {
      
      if (time_check( entries[i])) {
        char command[512] = "submit/noprint ";
        strcat(command, entries[i].command);
        // system(command);
        printf("command: %s\n", command);
        printf("executed: %s\n", entries[i].command);
      }
    }
    time_t t = time(NULL);
    sleep(60 - t % 60);
  }
  return 0;
}
