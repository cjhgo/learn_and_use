#include<iostream>
#include <ucontext.h>
#define STACK_SIZE 16384  
ucontext_t uca,ucb, ucall;

void context_init(ucontext_t * uc)
{
	getcontext(uc);
	uc->uc_link=&ucall;	  
  	uc->uc_stack.ss_sp = (char *) malloc(STACK_SIZE);
    uc->uc_stack.ss_size = STACK_SIZE;
    uc->uc_stack.ss_flags = 0;
}
void foo()
{
	std::cout<<"i am foo\n";
}

void bar()
{
	std::cout<<"i am bar\n";
}

int main(int argc, char const *argv[])
{
	ucontext_t main;
	getcontext(&main);
	std::cout<<"run to main:25\n";
	//getcontext(&uca);
	//getcontext(&ucb);
	std::cout<<"run to main:28\n";
	context_init(&uca);
	//context_init(&ucb);
	makecontext(&uca, foo,0);
	getcontext(&ucall);
	//uca.uc_link=&ucb;
	//makecontext(&ucb, bar,0);
	
	setcontext(&uca);
	//getcontext(&ucall);
	//setcontext(&ucb);
	std::cout<<"run to main:27\n";
	return 0;
}