

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;


template<typename elemType>
void display(const vector<elemType>& vec, ostream& os)
{
    typename vector<elemType>::const_iterator bit = vec.begin();
    typename vector<elemType>::const_iterator eit = vec.end();

    for (; bit not_eq eit; ++bit)
        os << *bit << ' ';
    os << endl;
}

void test1()
{
    display(vector<int>{1,2,3,4,5}, cout);
}

template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType& value)
{
    for(; first != last; ++first)
        if(value == *first)
            return first;
    return last;
}

void test2()
{
    const int _size = 8;
    int ia[_size] = {1, 1, 2, 3, 5, 8, 13, 21};
    
    vector<int> ivec(ia, ia + _size);
    list<int> ilist(ia, ia + _size);

    int *pia = find(ia, ia + _size, 1);
    if( pia not_eq ia + _size)
        cout << "find\n";

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 2);
    if(it != ivec.end())
        cout << "find\n";

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 1024);
    if( iter not_eq ilist.end())
        cout << "find\n";
}

int main()
{
    //test1();
    test2();

    return 0;
}