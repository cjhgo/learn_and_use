#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void* mymemcpy(void * dest, const void* src, size_t n)
{
  char* dest2 = (char*)dest;
  char* src2 = (char*) src;
  for(int i = n-1; i >= 0; i--)
  {
    *(dest2+i)=*(src2+i);
  }
  return dest;
}


int main(int argc, char const *argv[])
{
  char info[10]= { '0','1','2','3','4','5','6','7','8','9'};
  mymemcpy(info+5,info+3,3);
  for(int i = 0; i < 10; i++)
  {
    printf("%c", info[i]);
  }
  return 0;
}
