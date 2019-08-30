#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* mystrcpy(char* dest, const char* src)
{
  for(int i = 0; i < strlen(src); i++)
  {
    dest[i] = src[i];
  }
  return dest;
}

char* mystrcat(char* dest, const char* src)
{
  int i = strlen(dest);
  int j = 0;
  for(;src[j]!='\0'; j++ )
  {
    dest[i+j] = src[j];
  }
  dest[i+j]='\0';
  return dest;
}




int main(int argc, char const *argv[])
{
  char* strsrc = "hello";
  char* strdest = (char*)malloc(10*sizeof(char));
  strdest[8]='a';
  mystrcat(strdest, strsrc);
  
  printf("%s", strdest);
  printf("%d %d", strlen("hel"),sizeof "hel");
  return 0;
}
