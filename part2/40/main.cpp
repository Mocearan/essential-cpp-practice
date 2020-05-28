#include <iostream>
#include <vector>

using namespace std;

using seq_t = vector<int>;

void display(const seq_t& v);

void swap(int& v1, int& v2);

void bubble_sort(seq_t& v);

int main(void)
{
	vector<int> vec{8, 34, 3, 13, 1, 21, 5, 2};
	cout << "before sort: ";
	display(vec);
	
	bubble_sort(vec);

	cout << "after sort: ";
	display(vec);

	return 0;
}


void display(const seq_t& v)
{
	for(const auto& i : v )
		cout << i << ' ';
	cout << endl;
}

void swap(int& v1, int& v2)
{
	int t = v1;
	v1 = v2;
	v2 = t;
}

void bubble_sort(seq_t& v)
{
	for(auto& i : v)
		for(auto& j : v)
			if(i < j) swap(i, j);
}
