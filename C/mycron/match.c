#include "./crontab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int matchtime(int current_time, char *min) {
  char *ptr = min;
  int value = 0;
  while (1) {
    if (*ptr == 0) {
      // printf("not match\n");
      return 0;
    }
    value = strtol(ptr, &ptr, 10);

    if (current_time == value) {
      printf("match\n");
      return 1;
    }
    ptr++;
  }
}
extern time_t now;
int time_check( struct crontab_entry entrie) {
struct tm *tm = localtime(&now);

if ((strcmp("*", entrie.minute) != 0)&& matchtime(tm->tm_min, entrie.minute)== 0) {
    return 0;
}
if ((strcmp("*", entrie.hour) != 0)&& matchtime(tm->tm_hour, entrie.hour)== 0) {
    return 0;
}
if ((strcmp("*", entrie.day_of_month) != 0)&& matchtime(tm->tm_mday, entrie.day_of_month)== 0) {
    return 0;
}
if ((strcmp("*", entrie.month) != 0)&& matchtime(tm->tm_mon, entrie.month)== 0) {
    return 0;
}
if ((strcmp("*", entrie.day_of_week) != 0)&& matchtime(tm->tm_wday, entrie.day_of_week)== 0) {
    return 0;
}
return 1;
}
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// 测试函数
// void test_matchtime() {
//     int current_time = 30;
//     char min[] = "10,,,,,,,,20+++++++++ 30";

//     int result = matchtime(current_time, min);
//     assert(result == 1);  // 验证是否匹配成功

//     current_time = 15;
//     result = matchtime(current_time, min);
//     assert(result == 0);  // 验证是否匹配失败
// }

// int main() {
//     test_matchtime();  // 执行测试函数

//     return 0;
// }