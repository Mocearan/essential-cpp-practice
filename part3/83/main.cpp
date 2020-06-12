

/* =============================================================================
* -> FilePath     : /Mass/code/essential-cpp-practice/part3/83/main.cpp
* -> Author       : Mass
* -> Date         : 2020-06-12 20:18:05
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-06-12 20:18:05
* -> Description  : 
* =============================================================================*/



#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

/* =============================================================================
* -> Description: a quick but inelastic solution
* -> param {type} 
* -> return: 
* =============================================================================*/
vector<int> less_than_10(const vector<int> &vec)
{
    vector<int> nvec;
    for( int ix = 0; ix < vec.size(); ++ix)
        if(vec[ix] < 10) nvec.push_back(vec[ix]);

    return nvec;
}


/* =============================================================================
* -> Description: more general version
* -> param {type} 
* -> return: 
* =============================================================================*/
vector<int> less_than(const vector<int> &vec, int less_than_val)
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ++ix)
        if(vec[ix] < less_than_val) nvec.push_back(vec[ix]);

    return nvec;
}


/* =============================================================================
* -> Description: operation general version
* -> param {type} 
* -> return: 
* =============================================================================*/
vector<int> filter(const vector<int>& vec, int filter_val, bool (*pred)(int val, int pred_val))
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ++ix)
        if(pred(vec[ix], filter_val)) nvec.push_back(vec[ix]);

    return nvec;
}



/* =============================================================================
* -> Description: some operate funciton
* -> param {type} 
* -> return: 
* =============================================================================*/
bool less_than(int v1, int v2)
{
    return v1 < v2 ? true : false;
}

bool greater_than(int v1, int v2)
{
    return v1 > v2 ? true : false;
}

void t1()
{
    vector<int> big_vec {1,2,3,4,5,6};
    auto vec = filter(big_vec, 4, greater_than);
    for(const auto& i : vec) cout << i << endl;
}


/* =============================================================================
* -> Description: use find if
            find源码-》具名要求
            函数对象在参数传递时加括号
            bind 参数绑定
* -> param {type} 
* -> return: 
* =============================================================================*/
vector<int> filter_ver1(const vector<int>& vec, int filter_val, const less<int>& lt) // 这里如果不是const会产生临时对象的引用错误，为什么？
{
    vector<int> nvec;
    auto cit = vec.cbegin();

    // while((cit = find_if(cit, vec.cend(), bind(lt, placeholders::_1, filter_val))) not_eq vec.cend()){
    while((cit = find_if(cit, vec.cend(), bind2nd(lt, filter_val))) not_eq vec.cend()){
        nvec.push_back(*cit);
        cit++;
    }
   
    return nvec;
}

void t2()
{
    vector<int> big_vec {1,2,3,4,5,6};
    // less<int> ls = less<int>();
    auto vec = filter_ver1(big_vec, 4, less<int>());
    for(const auto& i : vec) cout << i << endl;
}


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



int main()
{
    // t1();
    //t2();
    t3();
    return 0;
}