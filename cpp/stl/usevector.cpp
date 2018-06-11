#include<iostream>
#include<vector>
int main(int argc, char const *argv[])
{
	std::vector<double> v;
	v.push_back(5);
	v.push_back(2.0);
	for(double e : v)
	{
		std::cout<<e<<std::endl;
	}
	return 0;
}