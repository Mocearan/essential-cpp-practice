#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void display_message(const string& msg, const vector<T>& vec, ostream& os = cout);

inline bool is_size_ok(int size);

inline const vector<int>* fibon_seq(int);

inline bool fibon_ele(int pos, int &elem);

bool print_sequence(int pos);





int main(void)
{
	int pos;


	while(true){
		cout << "Please enter a position" << endl;
		if(!(cin >> pos))
			break;

		int elem;
		if( fibon_ele(pos, elem)){
			cout << "element # " << pos
				<< " is " << elem << endl;
			print_sequence(pos);
		}
		else cout << "Sorry. Could not calculate element # "
			<< pos << endl;
	}

}




template<typename T>
void display_message(const string& msg, const vector<T>& vec, ostream& os)
{
	cout << msg;
	for(const auto& i : vec)
		cout << i << ' ';
}


bool is_size_ok(int size)
{
	const int max_size = 1024;
	const string msg{"Requested size is not supported"};

	if(size <= 0 or size > max_size){
		display_message<decltype(size)>(msg, vector<decltype(size)>(size), cerr);
		return false;
	}
	return true;
}

const vector<int>* fibon_seq(int size)
{
	const int max_size = 1024;
	static vector<int> elems;

	// check pos
	if ( not is_size_ok(size) ){
		return nullptr;
	}

	for(int ix = elems.size(); ix < size; ++ix){
		if(ix == 0 or ix == 1) elems.push_back(1);
		else elems.push_back(elems[ix - 1] + elems[ix - 2]);

	}

	return &elems;
}

bool fibon_ele(int pos, int &elem)
{
	auto pseq = fibon_seq(pos);

	if(not pseq)
	{elem = 0; return false;}

	elem = (*pseq)[pos - 1];
	return true;
}

bool print_sequence(int pos)
{
	if( pos <= 0 or pos >= 1024){
		cerr << "invalid position: " << pos	
			<<	" -- cannot handle request!\n";

		return false;
	}

	cout << "The Fibonacci Sequence for "
		<< pos << " positions: \n\t";

	auto fibo = fibon_seq(pos);
	size_t ix = 1;
	for (auto& i : *fibo)
		cout << i << (not( ix++ % 10) ? "\n\t" : " " );
	
	cout << endl;

	return true;
}
