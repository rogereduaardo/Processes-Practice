#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) 
{
  printf("HandsOn Processes\n");
  printf("Code by Roger Martinez\n");

  pid_t pid = getpid();
  pid_t ppid = getppid();
  printf("pid: %d, ppid: %d\n", pid, ppid);
  
  return 0;
}