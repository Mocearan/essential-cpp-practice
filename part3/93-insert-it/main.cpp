
/* =============================================================================
* -> FilePath     : /essential-cpp-practice/part3/93-insert-it/main.cpp
* -> Author       : Mass
* -> Date         : 2020-07-08 10:28:41
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-07-08 10:29:04
* -> Description  : 
        insert iterator
* =============================================================================*/

#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

/* =============================================================================
* -> Description: function template for general version
            template
            具名要求
* -> param {type} 
* -> return: 
* =============================================================================*/
template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType& val, Comp pred)
{
    while(
        (first = find_if(first, last, 
                                bind2nd(pred, val))) not_eq last){
            cout << "found value: " << *first << endl;
            *at++ = *first++;
    }
    return at;
}

void t3()
{
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> vec {ia, ia + elem_size};

    int ia2[elem_size];
    vector<int> ivec2(elem_size);

    //filter(ia, ia + elem_size, ia2, elem_size, less<int>());
    filter(vec.begin(), vec.end(), ivec2.begin(), 4, greater<int>());
}


/* =============================================================================
* -> Description: 
        上述示例 ， 传入一个已知容器。为保at++安全，人为拷贝源容器大小一致的目标容器。
        insertion adapter用以避免使用assignment运算符。
* -> param {type} 
* -> return: 
* =============================================================================*/
void t4()
{
    vector<int> vec{12, 8, 43, 0, 6, 21, 3, 7};

    vector<int> result_vec;
    unique_copy(vec.begin(), vec.end(), back_inserter(result_vec));

    vector<int> svec_res;
    unique_copy(vec.begin(), vec.end(), inserter(svec_res, svec_res.end()));

    //list and deque
    list<int> front_res;
    copy(vec.begin(), vec.end(), front_inserter(front_res));
}

int main()
{
    //t1();
    //t2();
    //t3();
    t4();

    return 0;
}