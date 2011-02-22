// -------------------
// FileInputOutput.c++
// -------------------

/*
% FileInputOutput.c++.app FileInputOutput.c++
*/

#include <cassert>  // assert
#include <fstream>  // ifstream
#include <iostream> // endl, getline, ios_base::sync_with_stdio

int main (int argc, char* argv[]) {
    using namespace std;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    ifstream fin(argv[1]);
    assert(fin);

    char a[80];
    while (fin.getline(a, 80))
        cout << a << endl;

    return 0;}
