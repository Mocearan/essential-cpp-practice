

/* =============================================================================
* -> FilePath     : /Mass/code/essential-cpp-practice/part3/90/main.cpp
* -> Author       : Mass
* -> Date         : 2020-06-23 09:32:20
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-06-23 09:32:32
* -> Description  : 
* =============================================================================*/

#include <map>
#include <string>
#include <iostream>
using namespace std;

void t1()
{
    map<string, int> word;

    string tword;
    while(cin>>tword)
        word[tword]++;

    //map<string, int>::iterator it = word.begin();
    //auto it = word.begin();
    
    //for (; it not_eq word.end(); ++it)
    //    cout << "key: " << it->first << "value: " << it->second << endl;
    
    for(const auto& it : word){  // ctrl + d
        cout << "key: " << it.first << " value: " << it.second << endl;
    }


    // search

    int count = 0;
    cout << "words you want search : ";
    cin.clear();
    cin >> tword;

    //1.
    //if(not (count = word[tword])) // insert when none
    //   ;

    //2.
    //word.find("vermeer"); // return iterator when exist, and end() when none;
    map<string, int>::iterator it;
    it = word.find(tword);
    if(it not_eq word.end())
        count = it->second;
    
    //3.
    if(word.count(tword))
        count = word[tword];

    cout << tword << " count: " << count << endl;
}
 
int main( )
{
    t1();
    return 0;
}