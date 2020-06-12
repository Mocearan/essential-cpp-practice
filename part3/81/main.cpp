

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <string>

// 泛型算法
#include <algorithm>

using namespace std;

bool grow_vec(vector<int>& vec, int elem)
{
    while(vec.back() < elem){
        if(vec.size() == 0 or vec.size() == 1)
            vec.push_back(1);
        else
            vec.push_back(vec[vec.size() - 1] + vec[vec.size() -  2]);
    }
    
    return (elem == vec.back()) ? true : false;
}


bool is_elem(vector<int>& vec, int elem)
{
    // check index of elem exists
    while(vec.size() == 0 or vec.size() == 1)
        vec.push_back(1);
    //int max_value = *max_element(vec.cbegin(), vec.cend() );
    int max_value = vec.back();
    if(max_value < elem)
        return grow_vec(vec, elem);

    if(max_value == elem)
        return true;

    // if not sorted.
    auto temp(vec);//copy(vec.begin(), vec.end(), temp.begin());
    sort(temp.begin(), temp.end());
    return binary_search(temp.begin(), temp.end(), elem);
}


int main()
{
    vector<int> a;
    cout << is_elem(a, 13) << endl;
    cout << is_elem(a, 14) << endl;
    return 0;
}