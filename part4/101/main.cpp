
/* =============================================================================
* -> FilePath     : /essential-cpp-practice/part4/101/main.cpp
* -> Author       : Mass
* -> Date         : 2020-07-09 10:49:17
* -> version      : 
* -> LastEditors  : Mass
* -> LastEditTime : 2020-07-09 10:49:37
* -> Description  : 
* =============================================================================*/

#include "stack.h"

#include <iostream>

int main()
{
    stack st;
    st.push("hhh");
    st.push("hhh");
    st.push("aaa");
    st.push("bbb");

    cout << st.size() << endl;

    if(st.find("hhh")){
        cout << st.count("hhh") << endl;
    }
}