
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

void show_message(char *msg)
{    
  cout<<msg<<endl;
  cout<<(void*)msg<<endl;
  // msg[1]='!';
  // cout<<msg<<endl;
}

int main(int argc, char const *argv[])
{
  char * temp1 = "hello,world";
  char * temp2 = "hello,world";
  cout<<(void*)temp1<<endl<<(void*)(temp2)<<endl<<(temp1==temp2)<<endl;
  char * temp3 = temp1+2;
  cout<<temp3<<endl;
  // *temp3 = '!';
  // cout<<temp1<<endl<<temp2<<endl;
  char* temp4 = "this is a message";
  cout<<(void*)temp3<<endl;
  show_message("this is a message");
  return 0;
}