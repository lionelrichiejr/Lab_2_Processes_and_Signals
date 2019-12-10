	/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int i = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  i = 1000000001;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1){
  alarm(1); //Schedule a SIGALRM for 1 second
  i = 0;
  while(i < 1000000000) { i++; } //busy wait for signal to be delivered
  printf("Turing was right!\n");
  }
  return 0; //never reached
}