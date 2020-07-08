
/* =============================================================================
* -> FilePath     : /essential-cpp-practice/part3/97-practice/main.cpp
* -> Author       : Mass
* -> Date         : 2020-07-08 11:22:49
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-07-08 11:22:49
* -> Description  : 
* =============================================================================*/

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>  
#include <fstream>
#include <set>

using namespace std;


void t1()
{
    map<string, int> word;
    set<string> word_exclusion{"hello","world"};
    string tword;



    ifstream in_file("in_file.txt");
    ofstream out_file("out_file.txt");

    if(not in_file or not out_file){
        cerr << "!! unable to open the necessary files.\n";
        return;
    }

    while (in_file >> tword){
        if (word_exclusion.count(tword))
            continue;
        word[tword]++;
    }

    for (const auto &i : word)
        out_file << i.first << " ( " << i.second << " )" << endl;
    out_file << endl;
}

template<typename elemType>
void display_vec(const vector<elemType>& vec, ostream &os = cout, int len = 8)
{
    typename vector<elemType>::const_iterator iter = vec.begin(), end_it = vec.end();
    int elem_cnt = 1;
    while(iter not_eq end_it)
        os << *iter++ << (not(elem_cnt++ % len) ? '\n' : ' ');
    os << endl;
}

void t2()
{
    struct LessThan{
        bool operator()(const string &s1, const string &s2) { return s1.size() < s2.size(); }
    };

    ifstream in_file("in_file.txt");
    ofstream out_file("out_file2.txt");

    if (not in_file or not out_file)
    {
        cerr << "!! unable to open the necessary files.\n";
        return;
    }

    vector<string> text;
    string word;

    while(in_file >> word)
        text.push_back(word);
    sort(text.begin(), text.end(), LessThan());

    display_vec(text, out_file);
}

using vstring = vector<string>;
using mvstring = map<string,vstring>

void t3()
{

}

int main()
{
    //t1();
    t2();
    //t3();
    return 0;
}