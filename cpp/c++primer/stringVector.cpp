
#include<iostream>
#include<vector>
#include<map>
#include<memory>
using namespace std;

class mystring
{
public:
  mystring():data(nullptr){};
  mystring(const mystring& from)
  {
    this->data=new char[5]{'a','b','c','e','1'};
  }
  mystring& operator=(mystring rhs)
  {
    using std::swap;
    swap(*this, rhs);
    return *this;
  }
  mystring(mystring&& from) //noexcept
  { 
    cout<<"\ncall me "<<(void*)from.data;
    this->data=from.data;
    from.data=nullptr;
  }
  ~mystring()
  {
    if(data)
    delete data;
  }
// private:
  char * data;
};
class StrVec
{
public:
  StrVec():elements(nullptr),firest_free(nullptr),cap(nullptr){}
  StrVec(const StrVec&);
  StrVec(StrVec&&);
  StrVec& operator=(const StrVec&);
  StrVec& operator=(StrVec&&);
  ~StrVec(){free();}
  void push_back(const mystring& s);
  void push_back(mystring&& s);
  size_t size() const {return firest_free-elements;}
  size_t capacity()const {return cap-elements;}
  mystring* begin()const {return elements;}
  mystring* end()const {return firest_free;}
private:
  mystring* elements,*firest_free,*cap;
  allocator<mystring> alloc;
  void chk_n_alloc()
  {
    if(size()==capacity())
    {
      cout<<size()<<"full\n";
      reallocate();
    }
      
  };
  pair<mystring*,mystring*> alloc_n_copy(const mystring*, const mystring*);
  void free();
  void reallocate();  
  void show();
};

void StrVec::push_back(const mystring& s)
{
  chk_n_alloc();
  alloc.construct(firest_free++, s);
  show();
}
void StrVec::push_back(mystring&& s)
{
  chk_n_alloc();
  alloc.construct(firest_free++, std::move(s));
}
pair<mystring*,mystring*> StrVec::alloc_n_copy(const mystring* b, const mystring* e)
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
StrVec::StrVec(StrVec&& rhs)
{
  this->elements = rhs.elements;
  this->firest_free = rhs.firest_free;
  this->cap = rhs.cap;
  rhs.elements=rhs.firest_free=rhs.cap=nullptr;  
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
  auto newdata=alloc_n_copy(rhs.begin(),rhs.end());
  free();
  this->elements = newdata.first;
  this->firest_free=this->cap=newdata.second;
  return *this;
}
StrVec& StrVec::operator=(StrVec&& rhs)
{
  if(this != &rhs)
  {
    free();
    this->elements = rhs.elements;
    this->firest_free = rhs.firest_free;
    this->cap = rhs.cap;
    rhs.elements=rhs.firest_free=rhs.cap=nullptr;  
  }
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
    // alloc.construct(dest++, *elem++);
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
    cout<<p++<<" "<<(void *)(*p).data<<" "<<*((*p).data)<<"\t";
  }
  cout<<endl;
}
int main(int argc, char const *argv[])
{
  StrVec v;
  char * c = new char[5]{'a','b','c','e','1'};
  cout<<sizeof(c)/sizeof(c[0])<<sizeof(c[0])<<c[3]<<c[5]<<endl;
  cout<<c<<endl;
  mystring a;
  a.data=c;
  cout<<a.data<<endl;
  for(size_t i = 0; i < 10; i++)
  v.push_back(a);
  
  char * y = new char[10];
  cout<<endl<<(void*)c<<endl<<(void*)y<<endl;
  
  StrVec vv(std::move(v));
  StrVec vvv;
  vvv=v; 
  printf("%d \t %d \t %d",v.size(),vv.size(),vvv.size());
  return 0;
}