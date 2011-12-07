#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#define ARR_SIZE 16

void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    printf("Caught segfault at address %p\n", si->si_addr);
    exit(0);
}

int main() {
  int i;
  char arr[ARR_SIZE] = {0};
  struct sigaction sa = {0};

  sigemptyset(&sa.sa_mask);
  sa.sa_sigaction = segfault_sigaction;
  sa.sa_flags   = SA_SIGINFO;

  sigaction(SIGSEGV, &sa, NULL);

  for( i = 0; i < ARR_SIZE; ++i)
    arr[i] = i+5;
  puts("Test 2");
  printf("%d",**((int**)&arr[0]));
  return 0;
}
