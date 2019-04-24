
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<memory>
using namespace std;

class StrVec
{
public:
  StrVec():elements(nullptr),firest_free(nullptr),cap(nullptr){}
  StrVec(const StrVec&);
  StrVec(StrVec&&);
  StrVec& operator=(const StrVec&);
  StrVec& operator=(StrVec&&);
  ~StrVec(){free();}
  void push_back(string& s);
  size_t size() const {return firest_free-elements;}
  size_t capacity()const {return cap-elements;}
  string* begin()const {return elements;}
  string* end()const {return firest_free;}
private:
  string* elements,*firest_free,*cap;
  allocator<string> alloc;
  void chk_n_alloc()
  {
    if(size()==capacity())
    {
      cout<<size()<<"full\n";
      reallocate();
    }
      
  };
  pair<string*,string*> alloc_n_copy(const string*, const string*);
  void free();
  void reallocate();  
  void show();
};

void StrVec::push_back(string& s)
{
  chk_n_alloc();
  alloc.construct(firest_free++, s);
  show();
}
pair<string*,string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
  auto data = alloc.allocate(e-b);
  return {data, uninitialized_copy(b,e,data)};
}
void StrVec::free()
{
  if(elements)
  {
    for(auto p = firest_free;p!=elements;)
    alloc.destroy(--p);
    alloc.deallocate(elements,cap-elements);
  }
}
StrVec::StrVec(const StrVec& s)
{
  auto newdata=alloc_n_copy(s.begin(),s.end());
  this->elements = newdata.first;
  this->firest_free=this->cap=newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
  auto newdata=alloc_n_copy(rhs.begin(),rhs.end());
  free();
  this->elements = newdata.first;
  this->firest_free=this->cap=newdata.second;
  return *this;
}

void StrVec::reallocate()
{
  show();
  auto newcap = size() ? 2*size():1;
  auto newdata = alloc.allocate(newcap);
  auto dest = newdata;
  auto elem = elements;
  for(size_t i = 0; i != size();i++)
  {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements=newdata;
  firest_free=dest;
  cap=elements+newcap;
}
void StrVec::show()
{
  cout<<"now show"<<endl;
  for(auto p = elements;p!=firest_free;)
  {
    cout<<p++<<"\t";
  }
  cout<<endl;
}
int main(int argc, char const *argv[])
{
  StrVec v;
  string a = "abc";
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);  
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);  
  v.push_back(a);  
  return 0;
}