#include <iostream>

using namespace std;

bool fibon_ele(int, int&);

int main(void)
{
    int pos;
    cout << "Please enter a position" << endl;
    cin >> pos;

    int elem;
    if( fibon_ele(pos, elem))
        cout << "element # " << pos
            << " is " << elem << endl;
    else cout << "Sorry. Could not calculate element # "
            << pos << endl;
}


bool fibon_ele(int pos, int& elem)
{
    // check pos
    if ( pos <= 0 or pos > 1024)
        {elem = 0; return false;}
    
    elem = 1;
    int n_2 = 1, n_1 = 1;

    for(int ix = 3; ix <= pos; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;
    }

    return true;
}