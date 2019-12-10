	/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int i = 0;
int seconds = 0;

void ALRM_handler(int signum)
{ //SIGALRM signal handler
  seconds++;
  i = 1000000001; //break out of busy loop on return
  }

void INT_handler(int signum)
{ //SIGINT signal handler
  printf("\nProgram ran for %d seconds\n", seconds);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, ALRM_handler); //register handler to handle SIGALRM
  signal(SIGINT, INT_handler); //register handler to handle SIGINT
  while(1){
    alarm(1); //Schedule a SIGALRM for 1 second
    while(i < 1000000000) { i++; } //busy wait for signal to be delivered
    i = 0;
  }
  return 0; //never reached
}			