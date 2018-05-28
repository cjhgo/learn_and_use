#include<iostream>
#include<functional>
#include<pthread_tools.h>

class usebind
{
public:
	usebind(){};
	~usebind(){};
	void func(int i)
	{
		std::cout<<i<<std::endl;
	}
	
};


void* foo(void*)
{
	std::cout<<5;
}


void bar(std::function<void()> f)
{
	f();
}
void bal()
{
	std::cout<<"i am bal \n";
}
void boo(void (*fn)())
{
	fn();
}
int main(int argc, char const *argv[])
{
	usebind u;
	u.func(5);
	pthread_t t;
	auto fnf= std::bind(&usebind::func, &u, 88);
	fnf();
	bar(fnf);
	Thread tt;
	tt.start(fnf);
	tt.join();
	boo(bal);
	boo(fnf);
	//pthread_create(&t, NULL, foo, NULL);
//	pthread_create(&t, NULL, fnf, NULL);
//	pthread_join(t, NULL);
	return 0;
}

// std::_Bind<
// 		std::_Mem_fn<
// 			void (usebind::*)(int)
// 		>
// 		(usebind*, int)
// >