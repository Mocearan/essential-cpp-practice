
#include "main.h"

enum class ns_type:char {
    ns_fibon,
    ns_lucas,
    ns_pell,
    ns_triang,
    ns_square,
    ns_pent
};

const vector<int>* (*seq_ptr_array[])(int) = {
    fibon_seq,
    lucas_seq,
    pell_seq,
    triang_seq,
    square_seq,
    pent_seq
};

template<typename T>
void display_message(const string& msg, const vector<T>& vec, ostream& os)
{
	cout << msg;
	for(const auto& i : vec)
		cout << i << ' ';
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

const vector<int>* lucas_seq(int)
{
	return nullptr;
}
const vector<int>* pell_seq(int)
{
	return nullptr;
}
const vector<int>* triang_seq(int)
{
	return nullptr;
}
const vector<int>* square_seq(int)
{
	return nullptr;
}
const vector<int>* pent_seq(int)
{
	return nullptr;
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


int main(void)
{
	int pos;
	
	while(true){
		cout << "Please enter a position" << endl;
		if(!(cin >> pos))
			break;

		int elem;
		if( fibon_ele(pos, elem, seq_ptr_array[(int)ns_type::ns_fibon])){
			cout << "element # " << pos
				<< " is " << elem << endl;
			print_sequence(pos);
		}
		else cout << "Sorry. Could not calculate element # "
			<< pos << endl;
	}

}




