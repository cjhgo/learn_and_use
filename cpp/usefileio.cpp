#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
int main(int argc, char const *argv[])
{
    ifstream myfile;
    myfile.open("train.csv");
    string line;
    int x;
    double y;
    char dot;
    vector<int> xv;
    vector<double> yv;
    stringstream iss;
    //line:23,11.22
    while(getline(myfile, line))
    {    
        iss<<line;
        iss>>x>>dot>>y;
        xv.push_back(x);
        yv.push_back(y);
        iss.clear();
    }
    cout<<xv.size()<<"\t"<<yv.size()<<endl;
    return 0;
}