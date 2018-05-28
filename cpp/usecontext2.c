/* This example shows the usage of makecontext().                    */

#define _XOPEN_SOURCE_EXTENDED 1
#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include <errno.h>

 #ifdef _LP64
  #define STACK_SIZE 2097152+16384 /* large enough value for AMODE 64 */
 #else
  #define STACK_SIZE 16384         /* AMODE 31 addressing */
 #endif

void func(int);

ucontext_t context, *cp = &context;

int main(void) {

  int  value = 122;

  getcontext(cp);
  context.uc_link = 0;
  if ((context.uc_stack.ss_sp = (char *) malloc(STACK_SIZE)) != NULL) {
    context.uc_stack.ss_size = STACK_SIZE;
    context.uc_stack.ss_flags = 0;
             errno = 0;
    makecontext(cp,func,1,value);
              if(errno != 0){
                perror("Error reported by makecontext()");
                return -1;         /* Error occurred exit */ }
  }
  else {
    perror("not enough storage for stack");
    abort();
  }
  printf("context has been built\n");
  setcontext(cp);
  perror("returned from setcontext");
  abort();

}

void func(int arg) {

  printf("function called with value %d\n",arg);
  printf("process will exit when function returns\n");
  return;

}