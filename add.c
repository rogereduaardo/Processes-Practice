#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  //Displays usage if not enough args
  if (argc < 3)
  {
    printf("Usage: %s NUM1 NUM2\n", argv[0]);
    return 1;
  }
  //Hums should be single digit
  if ((strlen(argv[1]) != 1) && (strlen(argv[2]) != 1))
  {
   printf("Usage single digit number\n");
    return 2;
  }
  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);
  int sum = num1 + num2;
  return sum;
}