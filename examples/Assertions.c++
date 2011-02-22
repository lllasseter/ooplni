// --------------
// Assertions.c++
// --------------

/*
Turn OFF assertions at compile time with NDEBUG.
% g++ -ansi -pedantic -DNDEBUG -Wall Assertions.c++ -o Assertions.c++.app
% Assertions.c++.app
*/

//#define NDEBUG

#include <cassert>  // assert
#include <iostream> // cout, endl

int inc (int v) {
    return v + 1;}

int main () {
    using namespace std;
    cout << "Assertions.c++" << endl;

    assert(inc(2) == 3);
    assert(inc(2) == 4);

    cout << "Done." << endl;
    return 0;}

/*
Assertions.c++
Assertion failed: (inc(2) == 4), function main, file Assertions.c++, line 24.
*/
