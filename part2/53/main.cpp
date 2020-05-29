#include "main.h"
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


void display(const seq_t& v, ostream& os)
{
	for(const auto& i : v )
		os << i << ' ';
	os << endl;
}

void swap(int& v1, int& v2)
{
	int t = v1;
	v1 = v2;
	v2 = t;
}

void bubble_sort(seq_t& v, ostream* ofile)
{
	for(auto& i : v)
		for(auto& j : v)
			if(i < j){
				if(ofile)
					(*ofile) << "about to call swap! ix: " << i						<< " jx: " << j << "\tswapping: "
						<< v[i] << " with " << v[j] << endl; 

				swap(i, j);
			} 
}
