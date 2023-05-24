#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) 
{
  printf("HandsOn Processes\n");
  printf("Code by Roger Martinez\n");

  pid_t pid = getpid();
  pid_t ppid = getppid();
  printf("pid: %d, ppid: %d\n", pid, ppid);

  int result = system("ps");
  printf("result: %d\n", result);

  result = system("pstree");
  printf("result: %d\n", result);
  
  return 0;
}