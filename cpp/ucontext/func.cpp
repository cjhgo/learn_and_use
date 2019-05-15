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
void foo(int a, int b)
{
	std::cout<<"i am foo\n";
  std::cout<<a+b<<std::endl;
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
	
	makecontext(&uca, (void(*)())foo,2,3,5);	
	setcontext(&uca);	
	std::cout<<"run to main:27\n";
	return 0;
}