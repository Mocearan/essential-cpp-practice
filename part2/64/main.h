
#include <iostream>
#include <vector>

using namespace std;

//const int seq_cnt = 6; //在头文件的const变量和inline函数带定义一个性质。
//                          需要进行编译时替换，且生命周期仅在文件作用域内。
//extern const vector<int>* (*seq_ptr_array[seq_cnt])(int);

const vector<int>* fibon_seq(int);
const vector<int>* lucas_seq(int);
const vector<int>* pell_seq(int);
const vector<int>* triang_seq(int);
const vector<int>* square_seq(int);
const vector<int>* pent_seq(int);


extern const vector<int>* (*seq_ptr_array[])(int);



template<typename T>
void display_message(const string& msg, const vector<T>& vec, ostream& os = cout);

inline bool is_size_ok(int size)
{
	const int max_size = 1024;
	const string msg{"Requested size is not supported. "};

	if(size <= 0 or size > max_size){
		display_message<decltype(size)>(msg, vector<decltype(size)>(size), cerr);
		return false;
	}
	return true;
}



inline bool fibon_ele(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = nullptr)
{
	auto pseq = (*seq_ptr)(pos);
    if(!pseq){
        display_message("\n\rInternal Error: seq_ptr is set to null! ", vector<decltype(pos)>());
        return false;
    }

	if(not pseq)
	{elem = 0; return false;}

	elem = (*pseq)[pos - 1];
	return true;
}


bool print_sequence(int pos);

