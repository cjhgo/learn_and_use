#include <iostream>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>
#include <boost/version.hpp>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>
using namespace std;  
int main(int argc, char const *argv[])
{
    char str[] = "%s => %d, %s";
    
    cout << boost::format(str) % "apples" % 7%"i like you!"<< "\n";
    boost::filesystem::path path(argv[0]);
    cout<<"file exist?:"<<boost::filesystem::exists(path)<<std::endl;
    cout<<BOOST_VERSION;
}