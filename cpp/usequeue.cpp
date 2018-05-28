#include<queue>
#include<vector>
#include<iostream>

class www
{
public:
	www(){};
	~www(){
		std::cout<<"????"<<std::endl;
	};
	static www& getinstance(){
		static www singleton;
		return singleton;
	};
	std::queue<int> q;
	void launch(int a)
	{
		std::cout<<q.size()<<std::endl;
		q.push(a);
		std::cout<<q.size()<<std::endl;
	};
};

class usequeue
{
public:
	std::queue<int> q;
	void launch(int a)
	{
		www::getinstance().launch(a);
	}
	usequeue(){};
	~usequeue(){};
	
};
int main(int argc, char const *argv[])
{

	usequeue u;
	u.launch(5);
	u.launch(5);
	u.launch(5);
	u.launch(5);
	u.launch(5);

	std::queue<int> qu;
	for (int i = 0; i < 6; ++i)
	{
		qu.push(i);
	}
	std::cout<<qu.front()<<std::endl;
	std::cout<<qu.back()<<std::endl;
	std::vector<int> temp{1,1,0,0};
	std::vector<std::vector<int>> v;
	v.push_back(temp);
	for(auto x : v[0])
		std::cout<<x;
	for(auto& x : v[0])
		std::cout<<x;
	return 0;
}