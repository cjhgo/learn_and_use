#include<map>
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;

map<string,string> buildMap(ifstream& map_file)
{
    map<string,string> trans_map;
    string key,value;
    while(map_file >> key && getline(map_file,value))
    {
        if( value.size() > 1)
           trans_map[key]=value;
    }
    return trans_map;
}
string transform(string word, map<string,string>trans_map)
{
    auto map_it = trans_map.find(word);
    if(map_it != trans_map.end())
    return map_it->second;
    else
    return word; 
}
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while( getline(input, text))
    {
        istringstream stream(text);
        string word;
        while(stream >> word)
        {
          cout<<transform(word, trans_map);
        }
        cout<<endl;
   
    }
}
int main(int argc, char* argv)
{
    ifstream map_file("a.txt");
    ifstream input("b.txt");
    word_transform(map_file, input);
    map<string,int> mymap = {
        {"chen", 5},
        {"zhao", 8},
        {"wang", 10}
    };
    //mymap.at("liu") = 33;
    mymap["li"] = 33;
}
