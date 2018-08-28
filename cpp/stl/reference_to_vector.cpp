#include<iostream>
#include<vector>
class V
{
public:
	std::vector<double> v;
	V()
	{
		v.resize(4,1);
	};
	void show()
	{
		for(auto e: v)
			std::cout<<e<<std::endl;
        std::cout<<std::endl;
	};
	double& gete(size_t i)
	{
		return v[i];
	}
};
int main(int argc, char const *argv[])
{
    V a;
    a.show();
    a.gete(1)=99;
    a.show();
	return 0;
}