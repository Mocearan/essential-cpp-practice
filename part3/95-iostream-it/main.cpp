
/* =============================================================================
* -> FilePath     : /essential-cpp-practice/part3/95-iostream-it/main.cpp
* -> Author       : Mass
* -> Date         : 2020-07-08 10:59:36
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-07-08 10:59:36
* -> Description  : 
            iostream iterator
* =============================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void t1()
{
    string word;
    vector<string> text;

    while(cin >> word)
        text.push_back(word);

    sort(text.begin(), text.end());

    for (int ix = 0; ix < text.size(); ++ix)
        cout << text[ix] << endl;
}

#include <iterator>
void t2()
{
    istream_iterator<string> is(cin); // a istream_iterator bind to stdin, a first , eof to last.
    istream_iterator<string> eof;     // default for eof.

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
}

#include <fstream>
void t3()
{
    ifstream in_file("in_file.txt");
    ofstream out_file("out_file.txt");

    if(not in_file or not out_file){
        cerr << "!! unable to open the necessary files.\n";
        return;
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    copy(text.begin(), text.end(), ostream_iterator<string>(out_file, " "));
}

int main()
{
    //t1();
    //t2();
    t3();
    return 0;
}