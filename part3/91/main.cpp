
/* =============================================================================
* -> FilePath     : /Mass/code/essential-cpp-practice/part3/90/main.cpp
* -> Author       : Mass
* -> Date         : 2020-06-23 09:32:20
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-06-23 09:32:32
* -> Description  : 
            map
* =============================================================================*/

#include <map>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void t1()
{
    map<string, int> word;
    string tword;
    set<string> word_exclusion{"sss"};

    while (cin >> tword)
    {
        if(word_exclusion.count(tword))
            continue;
        
        word[tword]++;
    }
}

void t2()
{
    int ia[10] = {1, 3, 5, 8, 5, 3, 1, 5, 8, 1};
    vector<int> vec(ia, ia + 10);
    set<int> iset(vec.begin(), vec.end());

    for(const auto& i : iset)
        cout << i << " ";
    cout << endl;

    auto iset2{iset};

    iset2.insert(19);
    iset2.insert(vec.begin(), vec.end());

    // algorizm
    std::vector<int> v_intersection;

    std::set_intersection(iset.begin(), iset.end(),
                          iset2.begin(), iset2.end(),
                          std::back_inserter(v_intersection));
    for (int n : v_intersection)
        std::cout << n << ' ';

    //set_union();
    //set_difference();
    //set_symmetric_difference();
}

int main( )
{
    //t1();
    t2();
    return 0;
}