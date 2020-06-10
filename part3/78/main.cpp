

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <string>

#include <algorithm>

using namespace std;

 void definition(void)
 {
    // empty container
    list<string> slist;
    vector<int> ivec;

    // size container, default initialize
    list<int> ilist(1024);
    vector<int> svec(32);

    // size container, specified initialize for each
    vector<int> ivec2(10, 1);
    list<string> slist1(16, "unassigned");

    // iterator container 
    int ia[ 8 ] = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> fib(ia, ia + 8);

    // copy container
    list<string> slist2;
    list<string> slist3(slist);
 }

 void indel(void)
 {
     deque<int> a_line;
     int val;
     while(cin >> val){
         a_line.push_back(val);

         int cur_val  = a_line.front();

         a_line.pop_front();
     }
 }

void inserts()
{
    int val = 8;

    list <int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list<int>::iterator it = list1.begin();
    while(it not_eq list1.end()){
        if(*it >= val){
            list1.insert(it, val); // iterator insert(iterator position, elemType value);
            break;
        }
        it++;
    }
    if(it == list1.end())
        list1.push_back(val);

    string sval("part two");
    list<string> slist;
    list<string>::iterator it1 = find(slist.begin(), slist.end(), sval);
    slist.insert(it1, 8, string("dunmmy"));//void insert(iterator position, int count, elemType value);


    int ia1[7] = {1,1,2,3,4,5,6};
    int ia2[4] = {4,6,67,8};
    list<int> elems{ia1, ia1 + 7};

    list<int>::iterator it = find(elems.begin(), elems.end(), 4);
    elems.insert(it, ia2, ia2 + 4);// void insert(iterator position, iterator2 first, iterator2 last);

    //iterator insert(iterator position);

}

void erase(void)
{
    list<string> slist;
    
    list<string>::iterator it = find(slist.begin(), slist.end(), "aaa");
    slist.erase(it);



    list<string>::iterator first = slist.begin()
                        , last = slist.end();
    string str = "a", sval = "val";
    list<string>::iterator it1 = find(first, last, str);
    list<string>::iterator it2 = find(first, last, sval);

    slist.erase(it1, it2);

    //slist.erase(it1, it1 + num_size); error: list并不支持iterator的偏移量
}


int main()
{
    
    inserts();
    return 0;
}