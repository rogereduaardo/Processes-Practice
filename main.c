#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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

  pid_t child_pid = fork();
  if (-1 == child_pid)
  {
    perror("fork");
    return 1;
  }
  if (child_pid)
  {
    printf("PARENT! pid: %d, ppid: %d, child_pid: %d\n", getpid(), getppid(), child_pid);
    int wait_status = 0;
    pid_t pid = wait(&wait_status);
    printf("PARENT: Returned from wait: pid: %d\n", pid);
    printf("PARENT: child exit status: %d\n", WEXITSTATUS(wait_status));
  }
  else
  {
    printf("CHILD:\n");
    char *argv[] = {"./add", "1", "2", NULL};
    char *envp[] = {NULL};
    int result = execve("./add", argv, envp);
    if (-1 == result)
    {
      perror("execve");
    }
  }
  return 0;
}