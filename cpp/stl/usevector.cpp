#include<iostream>
#include<vector>
int main(int argc, char const *argv[])
{
	std::vector<double> v;
	v.resize(4,0);
	for(double e : v)
	{
		std::cout<<e<<std::endl;
	}
	v={0,1,3,4};
	for(double e : v)
	{
		std::cout<<e<<std::endl;
	}
	std::cout<<v.size();
	v.clear();
	std::cout<<v.size();
	return 0;
}