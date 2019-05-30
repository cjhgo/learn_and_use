#include <vector>
#include <string>
using namespace std;


class Solution
{
public:
  vector<string> foo()
  {

  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  sol.foo();//will Segmentation fault
  return 0;
}