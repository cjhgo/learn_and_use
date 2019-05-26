#include <stdio.h>



void show_message(char *msg)
{    
  printf("%s\n%x\n",msg,msg );
  // msg[1]='!';
  // cout<<msg<<endl;
}

int main(int argc, char const *argv[])
{
  char * temp1 = "hello,world";
  char * temp2 = "hello,world";  
  char * temp3 = temp1+2;
  
  // *temp3 = '!';
  // cout<<temp1<<endl<<temp2<<endl;
  char* temp4 = "this is a message";
  printf("%x\n%x\n%x\n%x\n", temp1, temp2, temp3, temp4);
  show_message("this is a message");
  return 0;
}