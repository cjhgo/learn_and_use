#include <cstdio>
#include <iostream>
#include <ucontext.h>
#define STACK_SIZE 16384  
ucontext_t uca,ucb;

void context_init(ucontext_t * uc)
{
	getcontext(uc);
	uc->uc_link=0;	  
  uc->uc_stack.ss_sp = (char *) malloc(STACK_SIZE);
  uc->uc_stack.ss_size = STACK_SIZE;
  uc->uc_stack.ss_flags = 0;
}
void foo(int a, int b, int * c)
{
	std::cout<<"i am foo\n";
  printf("%x \t %x \t %d\n", a+b, c,*c);
}
void bar()
{
	std::cout<<"i am bar\n";
}

int main(int argc, char const *argv[])
{
	std::cout<<"run to main:25\n";

	std::cout<<"run to main:28\n";
	context_init(&uca);	
	int * c = new int(55); 
	int64_t d = (int64_t)c;
	printf("%x \t %x\n",c,d);
	makecontext(&uca, (void(*)())foo,3,3,5,(int64_t)c);	
	setcontext(&uca);	
	std::cout<<"run to main:27\n";
	return 0;
}