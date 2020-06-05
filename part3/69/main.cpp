

#include <vector>
using namespace std;

int min(int array[24])
{
}

int min(int* arrray, int size)
{
}

template<typename elemType>
elemType* find(const elemType* array, int size, const elemType& values)
{
#define INDEX_IMPL 0
#if INDEX_IMPL
    if(not array or size < 0)
        return nullptr;

    for(int ix = 0; ix < size; ++ix)
        if(array[ix] == values) return &array[ix];
    return nullptr;
#else
    if(not array or size < 1) return nullptr;

    for(int ix = 0 ; ix < size; ++ix, ++array)
        if(*array == values) return array;

    return nullptr;   
#endif
}

template<typename elemType>
elemType* find(const elemType* array, const elemType* sentinel, const elemType& values)
{
    if(not array or not sentinel)   return nullptr;

    for(; array != sentinel; ++array)
        if(*array == values) return array;

    return nullptr;
}

template<typename elemType>
inline elemType* begin(const vector<elemType> &vec)
{
    return vec.empty() ? 0 : &vec[0];
}

template<typename elemType>
inline elemType* end(const vector<elemType> &vec)
{
    return vec.empty() ? 0 : &(vec[vec.size()]+1);
}