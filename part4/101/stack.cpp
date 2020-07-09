
/* =============================================================================
* -> FilePath     : /essential-cpp-practice/part4/101/stack.cpp
* -> Author       : Mass
* -> Date         : 2020-07-09 10:49:22
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-07-09 10:49:22
* -> Description  : 
* =============================================================================*/

#include "stack.h"

bool stack::peek(string &elem)
{
    if (empty())
        return false;

    elem = _stack.back();
    return true;
}


bool stack::push(const string &elem)
{
    if (full())
        return false;

    _stack.push_back(elem);
    return true;
}
