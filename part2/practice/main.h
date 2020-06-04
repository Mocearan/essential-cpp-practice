

#include <vector>
#include <iostream>

using namespace std;

//2.2 
bool pentagonal(const int n, vector<int>& outvec);

template<typename T>
void display_message(const vector<T>& vec, const string& seq_type, ostream& os);

inline bool NumberIsOk(const int &number)
{
    if (number <= 0 || number > 100)
    {
        cerr << "value invalid: " << number	
		<<	" -- cannot handle request!\n";

		return false;
    }
    return true;
}
