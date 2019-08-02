#include <memory>
#include <mutex>
#include <iostream>

struct Mock
{

  ~Mock()
  {
    std::cout<<"run here\n";
  };
};

int main(int argc, char const *argv[])
{

  std::unique_ptr<Mock> a(new Mock), b(new Mock);

  a = std::move(b);
  std::cout<<"-------------\n";
  return 0;
}