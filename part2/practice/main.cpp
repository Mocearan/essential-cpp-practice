#include "main.h"

const vector<int>* pentagonal_seq(int size)
{
	static vector<int> elems;

	// check pos
	if ( not NumberIsOk(size) ){
		return nullptr;
	}

	for(int ix = elems.size() + 1; ix <= size; ++ix){
		elems.push_back(ix * (3*ix -1)/2);
	}

	return &elems;
}

auto pentagonal(const int n, int& elem) -> bool
{
	if(not NumberIsOk(n)){
		return false;
	}
	cout <<"xxxx";
	auto pseq = pentagonal_seq(n);

	if(not pseq)
	{ elem = 0; return false;}

	elem = (*pseq)[n - 1];
	return true;
}

auto display_message(const vector<int>& vec, const string& seq_type= "pantagonal"s, ostream& os = cout) -> void
{
	os << seq_type;
	for(const auto& i : vec)
		os << i << ' ';
	os << endl;
}


auto t22(void) -> void
{
	int pos;

	while(true){
		cout << "Please enter a position" << endl;
		if(!(cin >> pos))
			break;
		int elem;
		if( pentagonal(pos, elem))
			cout << "element # " << pos
				<< " is " << elem << endl;
		else cout << "Sorry. Could not calculate element # "
			<< pos << endl;
	}
}


template<typename T>
bool maxss(const T& a, const T& b)
{
	return a > b;
}

#include <algorithm>
template< class T >	
T maxss( std::initializer_list<T> ilist)
{
    return *std::max_element(ilist.begin(), ilist.end());
}

template<typename T>
T maxss( T a[], size_t n)
{
	auto max = a[0];
	for(size_t i = 1; i < n; ++i){
		//a[i] > max ? max = a[i]:0;
		if(a[i] > max)
			max = a[i];
	}
	return max;
}



void t26()
{
	if(maxss(1,2))
		cout << " > ";
	else cout << " < ";

	if(maxss(1.2,2.3))
		cout << " > ";
	else cout << " < ";

	if(maxss("zello"s,"world"s))
		cout << " > ";
	else cout << " < ";

	cout << maxss({1,2,3,4})<<" ";

	cout << maxss({1.2,2.2,3.0,4.4}) << " ";

	cout << maxss({"this"s, "is"s, "a"s, "word"s}) << " ";

	int a[] = {1,23,45,5,6};
	cout << maxss(a, 5) << " ";

	float b[] = {1.1,2.3,4.5,5.9,6.0};
	cout << maxss(b, 5) << " ";

	string c[] = {"this"s, "is"s, "a"s, "string"s, "zarray"s};
	cout << maxss(c, 5);

	cout << endl;
}


void tt()
{
	string a="aaa";
	a = "bbb";
	cout << a << endl;
}

auto main() -> int
{
	//t22();
	t26();
	//tt();

	return 0;
}