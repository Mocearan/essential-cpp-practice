
#include <iostream>
#include <vector>

using namespace std;

using seq_t = vector<int>;

void display(const seq_t& v, ostream& os= cout);

void swap(int& v1, int& v2);

void bubble_sort(seq_t& v, ostream* ofile= nullptr);
