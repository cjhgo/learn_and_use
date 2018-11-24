#include <iostream>
#include <boost/format.hpp>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>
using namespace std; 
string format(const string& format, ...)
{
    va_list args;
    va_start (args, format);
    size_t len = vsnprintf(NULL, 0, format.c_str(), args);
    va_end (args);
    vector<char> vec(len + 1);
    va_start (args, format);
    vsnprintf(&vec[0], len + 1, format.c_str(), args);
    va_end (args);
    return &vec[0];
}
 
int main()
{
    char str[] = "%s => %d, %s";
    cout << format(str, "apples", 7, "i like you!") << "\n";
    cout << boost::format(str) % "apples" % 7%"i like you!"<< "\n";
    char s[100];   
    sprintf(s,"%s => %d, %s", "apple", 7, "i like you!\n");
    cout<<s;
}