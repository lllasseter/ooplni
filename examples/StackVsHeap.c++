// ---------------
// StackVsHeap.c++
// ---------------

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl

int f (int n) {
    if (n == 0)
        return 0;
    return 1 + f(n - 1);}

int main () {
    using namespace std;
    cout << "StackVsHeap.c++" << endl;

    try {
        const int* const a = new int[30000000000000];} // 40000000000000 will fail
    catch (const bad_alloc& e) {
        assert(false);}

    {
    const int n = 999999;                              // 9999999 will fail
    assert(f(n) == n);
    }

    cout << "Done." << endl;
    return 0;}

/*
malloc: *** mmap(size=160000000000000) failed (error code=12)
*** error: can't allocate region
*** set a breakpoint in malloc_error_break to debug
*/

/*
*** [StackVsHeap.c++x] Segmentation fault
*/
