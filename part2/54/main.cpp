#include <iostream>
#include <vector>

using namespace std;

const vector<int>* fibon_ele(int);

bool print_sequence(int pos);

int main(void)
{
	int pos;


	while(true){
		cout << "Please enter a position" << endl;
		if(!(cin >> pos))
			break;

		int elem;
		if( fibon_ele(pos)){
			cout << "element # " << pos
				<< " is " << elem << endl;
			print_sequence(pos);
		}
		else cout << "Sorry. Could not calculate element # "
			<< pos << endl;
	}

}


const vector<int>* fibon_ele(int size)
{
	const int max_size = 1024;
	static vector<int> elems;

	// check pos
	if ( size <= 0 or size > 1024){
		 cerr << "fibon_ele(): oops: invalid size : "
		 	<< size << " -- can't fulfill request.\n";
		 return nullptr;
	}

	for(int ix = elems.size(); ix < size; ++ix){
		if(ix == 0 or ix == 1) elems.push_back(1);
		else elems.push_back(elems[ix - 1] + elems[ix - 2]);

	}

	return &elems;
}

bool print_sequence(int pos)
{
	if( pos <= 0 or pos >= 1024){
		cerr << "invalid position: " << pos	
			<<	" -- cannot handle request!\n";

		return false;
	}

	cout << "The Fibonacci Sequence for "
		<< pos << "positions: \n\t";

	auto fibo = fibon_ele(pos);
	size_t ix = 1;
	for (auto& i : *fibo)
		cout << i << (not( ix++ % 10) ? "\n\t" : " " );
	
	cout << endl;

	return true;
}
