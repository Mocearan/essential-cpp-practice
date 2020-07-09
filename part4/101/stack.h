
/* =============================================================================
* -> FilePath     : /essential-cpp-practice/part4/101/stack.h
* -> Author       : Mass
* -> Date         : 2020-07-09 10:48:44
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-07-09 10:48:44
* -> Description  : 
* =============================================================================*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class stack;

static stack *pt;
void process(const stack &);

class stack final
{
public:
    bool push(const string &);
    bool pop(string &elem);
    bool peek(string &elem);

    bool empty() { return _stack.empty(); }
    bool full();

    int size() { return _stack.size(); }

    bool find(const string &elem) const { return ::find(_stack.begin(), _stack.end(), elem) not_eq _stack.end(); }
    int count(const string &elem) const { return ::count(_stack.begin(), _stack.end(), elem); }

private:
    vector<string> _stack;
};

inline bool stack::full()
{
    return _stack.size() == _stack.max_size();
}