#include <bitset>
#include <iostream>
#include "dense_bitset.hpp"
#include "custom_bitset.hpp"
using namespace std;
/*
Printing numbers in binary format in C++
*/
void use_std_bitset()
{
  int x=998;
  bitset<32>y(x);
  bitset<64>why(1099511627776);
  cout<<why<<endl;
  cout<<y<<endl;
  // 00000000000000000000001111100110
  for(int i = 0; i < y.size();i++)
    cout<<y[i];
  cout<<endl;
  // 01100111110000000000000000000000
  // 注意字节序不一样

}
void use_dense_bitset()
{
  //denbse_bitset 只输出有效位
  graphlab::fixed_dense_bitset<128> fdb;
  graphlab::dense_bitset db;
  
  fdb.set_bit(0);
  fdb.set_bit(32);
  fdb.set_bit(65);
  
  for(auto e: fdb)
    cout<<e<<endl;
  // 0 32 65

  db.resize(128);
  db.set_bit(1);
  db.set_bit(3);
  db.set_bit(7);
  db.set_bit(32);
  db.set_bit(65);
  db.set_bit(66);
  db.set_bit(127);
  db.print();
  for(auto e: db)
    cout<<e<<endl;
  // 1 3 7


  size_t vid = 70;
  size_t vid_block = fdb.containing_word(vid);
  graphlab::fixed_dense_bitset<64> local_bitset;
  local_bitset.initialize_from_mem(&vid_block, 8);
  for(auto e: local_bitset)
  cout<<64+e;

  cout<<endl;
}
void use_custom_bitset()
{
  custom_bitset cb;
  cb.resize(129);
  cb.set_bit(33);
  cb.set_bit(34);
  cb.set_bit(65);
  cb.set_bit(69);
  cb.set_bit(128);
  cb.print();
  for(auto e: cb)
  std::cout<<e<<"\t";
  cb.fill();
  cb.print();
  // cb.clear();
  // cb.print();
  std::cout<<std::endl<<std::endl;
  for(auto e: cb)
  std::cout<<e<<"\t";
}
int main()
{
  //use_dense_bitset();
  use_custom_bitset();

}
