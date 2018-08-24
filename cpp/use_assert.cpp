#include<cassert>
#include<vector>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> a(5);
    vector<int> b(5);
    vector<int> c(4);
    assert(a.size() == b.size());
    assert(a.size() == c.size());
    return 0;
}
