#include<iostream>
#include<vector>


void test_capacity()
{
	std::cout<<"test cap ():\n";
	std::vector<int> arr(10000,1);
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.push_back(2);
	
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.resize(20);
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.reserve(500000);
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.shrink_to_fit();
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.clear();
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.shrink_to_fit();
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	std::vector<int>().swap(arr);		
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.resize(20,3);
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.push_back(4);
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.shrink_to_fit();
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
	arr.push_back(5);
	std::cout<<arr.size()<<"\t"<<arr.capacity()<<std::endl;
}

int main(int argc, char const *argv[])
{
	std::vector<double> v(10,5.1);
	// v.resize(4,0);
	for(double e : v)
	{
		std::cout<<e<<std::endl;
	}
	v={0,1,3,4};
	for(double e : v)
	{
		std::cout<<e<<std::endl;
	}
	std::cout<<v.size()<<std::endl;
	v.clear();
	std::cout<<v.size()<<std::endl;
	v.push_back(0.1);
	v.push_back(0.3);
	for(double e : v)
	{
		std::cout<<e<<"\t";
	}
	std::cout<<std::endl;
	v={1,7,2,8};
	auto b = v.begin()+2, e = v.begin()+4;
	std::vector<double> vv(b,e);
	for(auto e : vv)
	std::cout<<e<<"\t";

	test_capacity();
	return 0;
}