#include<iostream>
#include<vector>
#include<string>
#include<map>
#define SIZE 1024
/**
SIZE为1023时,正常运行
超过1023之后,程序运行报错segmentation fault
1024*1024*8B=8MB
**/
int main(int argc, char const *argv[])
{
    double array[SIZE][SIZE];
    return 0;
}