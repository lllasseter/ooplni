// ---------------
// InputOutput.c++
// ---------------

#include <iostream> // cin, cout, endl, getline, ios_base::sync_with_stdio

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    cout << "Enter:" << endl;
    char a[80];
    cin.getline(a, 80);
    cout << a << endl;

    return 0;}

/*
Enter:
abc
abc
*/
