#include <iostream>
#include <pthread.h>
class WWW
{
public:
	WWW(){};
	~WWW(){};
	static void* foo(void *)
	{
		std::cout<<"i am foo\n";
	}
	
};

int main(int argc, char const *argv[])
{
	pthread_t t;
	pthread_create(&t,NULL,WWW::foo,NULL);
	pthread_join(t, NULL);
	return 0;
}