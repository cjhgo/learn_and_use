
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <iostream>

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
        datalen = datalen;
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
        for(size_t i = 0; i < arraylen; i++)
        {
            std::bitset<8*sizeof(size_t)> tmp(array[i]);
            std::cout<<tmp<<std::endl;
        }
    }
private:
    inline static void bit_to_pos(size_t pos, size_t& byte_pos, size_t& bit_pos)
    {
        byte_pos = pos / (8*sizeof(size_t));
        bit_pos = (8*sizeof(size_t)) - pos % (8*sizeof(size_t));
    };
    size_t * array;
    size_t datalen;
    size_t arraylen;
};