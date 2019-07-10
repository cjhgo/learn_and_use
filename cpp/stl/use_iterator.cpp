#include<vector>
#include<algorithm>
#include<iterator>
#include<iostream>
using namespace std;


typedef std::vector<int> MyType;
typedef std::vector<int>::iterator MyTypeIterator;

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4};
    vector<int> v2;
    auto it = inserter(v, v.begin()+2);
    cout<<*(v.begin()+2)<<endl;
    *it = 9;
    *it = 10;
    for(auto e: v)
        cout<<e<<"\t";
    string s("abcde");
    string copy;
    reverse_copy(s.begin(),s.end(), inserter(copy,copy.begin()));
    cout<<"\n...\n"<<s<<"\n"<<copy<<endl;


    MyType mt = {1,2,3,4};
    MyTypeIterator mti = mt.begin()+1;
    std::cout<<*mti<<std::endl;
    // typename MyTypeIterator::reference val = *mti;
    MyTypeIterator::reference val = *mti;
    std::cout<<val<<endl;
    val = 33;
    std::cout<<*mti<<std::endl;
    typename MyTypeIterator::iterator_category jj;    
    return 0;
}
