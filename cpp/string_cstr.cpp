#include <iostream>
#include <string>
#include <sstream>
using namespace std;



void validate_string_c_str()
{
  const char * a;
  {
    std::string x("helloworld");
    a= x.c_str()+2;
    //如果x后续一直是只读的,那么使用c_str是没有问题的
    std::cout<<a<<std::endl;
    x="1232132";
    std::cout<<a<<std::endl;
  }
  //x此时已经被析构,a指针指向的内容是为定义的
  std::string y("qwewqrewrewrwe");
  //新构造的y会存放于原来的x所在的内存,此时打印a会看到y的内容
  std::cout<<a<<std::endl;
}


void validate_ss_str_c_str()
{
  stringstream ss("01234567890123456\t");
  stringstream t_ss("abcdefghijklmnopqrstuvwxyz");
  string str1(ss.str());

  const char* cstr1 = str1.c_str();
  const char* cstr2 = ss.str().c_str();
  std::cout<<cstr2<<ss.str().c_str()<<std::endl;  
  const char* cstr3 = ss.str().c_str();  
  std::cout<<cstr2<<cstr3<<std::endl;  
  const char* cstr4 = ss.str().c_str();  
  const char* t_cstr = t_ss.str().c_str();  
  std::cout << "------ The results ----------" << std::endl
      << "cstr1:\t" << cstr1 << endl
      << "cstr2:\t" << cstr2 << endl
      << "cstr3:\t" << cstr3 << endl
      << "cstr4:\t" << cstr4 << endl
      << "t_cstr:\t" << t_cstr << endl
      << "-----------------------------"  << endl;    
}


int main(int argc, char const *argv[])
{
  validate_string_c_str();
  validate_ss_str_c_str();
  return 0;
}