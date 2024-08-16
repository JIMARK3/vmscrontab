#include "crontab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int have_new_entrys() {
  char *mark_file = MARKNAME;

  if (remove(mark_file) == 0) {
    printf("have new entrys\n");
    return 1;
  }
  return 0;
}
// read file line by line