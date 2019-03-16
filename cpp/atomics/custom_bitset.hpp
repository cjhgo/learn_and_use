
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <iterator>
#include <cassert>

class custom_bitset
{

public:
  custom_bitset():array(NULL),datalen(0),arraylen(0)
  {};
  custom_bitset(size_t datalen):array(NULL),datalen(0),arraylen(0)
  {
    resize(datalen);
    clear();
  };
  void set(size_t pos, bool value)
  {
    if(value)set_bit(pos);
    else clear_bit(pos);
  };

  void set_bit(size_t pos)
  {
    size_t byte_pos, bit_pos;
    bit_to_pos(pos, byte_pos, bit_pos);
    array[byte_pos] |= (size_t(1) << bit_pos);
  };
  void clear_bit(size_t pos)
  {
    size_t byte_pos, bit_pos;
    bit_to_pos(pos, byte_pos, bit_pos);
    array[byte_pos] &= ~(size_t(1) << bit_pos);
  };
  bool empty()
  {
    for(size_t i = 0; i < arraylen; i++) if(array[i]) return false;
    return true;
  };
  

  void resize(size_t datalen)
  {
    this->datalen = datalen;
    size_t pre_arraylen = arraylen;
    arraylen = datalen/(8*sizeof(size_t)) + (datalen % (8*sizeof(size_t)) > 0 );    
    array = (size_t *)realloc(array, arraylen);
    if(arraylen > pre_arraylen)
    {
      for(size_t i = pre_arraylen; i < arraylen; i++)
      array[i]=0;
    }
  };
  void clear()
  {
    for(size_t i = 0; i < arraylen; i++) array[i] = 0;
  };
  inline void fill()
  {
    for (size_t i = 0;i < arraylen; ++i) array[i] = (size_t) - 1;
  };
  size_t pop_count() const
  {
    size_t ret = 0;
    for(size_t i = 0; i < arraylen; i++)
    {
      ret += __builtin_popcountl(array[i]);
    }
    return ret;
  };
  
  void print()
  {
    std::cout<<std::endl;
    for(size_t i = 0; i < arraylen; i++)
    {
      std::bitset<8*sizeof(size_t)> tmp(array[i]);
      std::cout<<tmp<<std::endl;
    }
    std::cout<<std::endl;
  }

  struct bit_pos_iterator
  {
    typedef std::input_iterator_tag iterator_category;
    typedef size_t value_type;
    typedef size_t difference_type;
    typedef const size_t reference;
    typedef const size_t* pointer;
    size_t pos;
    const custom_bitset* cb;
    bit_pos_iterator():pos(-1),cb(NULL){};
    bit_pos_iterator(const custom_bitset* const cb, size_t pos):pos(pos), cb(cb){};
    size_t operator *() const
    {
    return pos;
    };
    size_t operator ++()
    {
    if(cb->next_bit(pos) == false) return pos=(size_t)-1;
    return pos;
    };
    bool operator ==(const bit_pos_iterator& other ) const
    {
      assert(cb == other.cb);
      return this->pos == other.pos;
    };
    bool operator !=(const bit_pos_iterator& other ) const
    {
      assert(cb == other.cb);
      return this->pos != other.pos;
    }
  };
  typedef bit_pos_iterator iterator;
  typedef bit_pos_iterator const_iterator;



  bit_pos_iterator begin() const
  {
    size_t pos;
    if(first_bit(pos) == false) pos = (size_t)-1;
    return bit_pos_iterator(this, pos);
  };
  bit_pos_iterator end() const
  {
    return bit_pos_iterator(this, (size_t)-1);
  };

private:
  inline static void bit_to_pos(size_t pos, size_t& byte_pos, size_t& bit_pos)
  {
    byte_pos = pos / (8*sizeof(size_t));
    bit_pos = pos & (8*sizeof(size_t)-1);
  };
  inline bool next_bit(size_t& b) const
  {
    size_t bit_pos, byte_pos;
    bit_to_pos(b, byte_pos, bit_pos);
    size_t block = array[byte_pos];
    size_t pos = next_bit_in_block(bit_pos, block);
    if( pos != 0)
    {
      b = 8*sizeof(size_t)*byte_pos+ pos;
      if(b < datalen)
        return true;
      else
        return false;
    }
    else
    {
      for(size_t i = byte_pos+1; i < arraylen; i++)
      {
        if( array[i])
        {

          pos = 8*sizeof(size_t)*i + first_bit_in_block(array[i]);
          if( pos < datalen) 
          {
            b = pos;
            return true;
          }              
          else 
            return false;  
        }
      }
    }
    return false;  
  };
  inline size_t next_bit_in_block(size_t& b, size_t& block) const
  {
    size_t belowselectedbit = size_t(-1) - (((size_t(1) << b) - 1)|(size_t(1)<<b));
    size_t x = block & belowselectedbit ;
    if (x == 0) return 0;
    else return (size_t)__builtin_ctzl(x);
  };
  inline size_t first_bit_in_block(size_t& block) const
  {
    //std::cout<<(size_t)__builtin_ctzl(block)<<std::endl;
    if (block == 0) return 0;
    else return (size_t)__builtin_ctzl(block);
  };
  inline size_t first_bit(size_t& pos) const
  {
    for(size_t i = 0; i < arraylen; i++)
    {
      if(array[i])
      {
        pos =8*sizeof(size_t)*i+first_bit_in_block(array[i]);
        return true;
      }      
    }
    return false;
  }
  size_t * array;
  size_t datalen;
  size_t arraylen;
};