// -------------------
// FormattedOutput.c++
// -------------------

#include <cassert>  // assert
#include <ios>      // fmtflags
#include <iostream> // cout, endl, fixed, flags, ios_base, left, precision, scientific, streamsize
#include <iomanip>  // setfill, setprecision, setw
#include <sstream>  // ostringstream
#include <string>   // ==

int main () {
    using namespace std;
    cout << "FormattedOutput.c++." << endl;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    const double pi = 3.1415926536;

    {
    ostringstream out;
    out << pi;
    assert(out.str() == "3.14159");
    }

    {
    ostringstream out;
    out << setfill('x') << setprecision(3) << setw(10) << pi << pi;
    assert(out.str() == "xxxxxx3.143.14");
    }

    {
    ostringstream out;
    out << left << setfill('x') << setprecision(3) << setw(10) << pi;
    assert(out.str() == "3.14xxxxxx");
    }

    {
    ostringstream out;
    out << fixed << setfill('x') << setprecision(3) << setw(10) << pi;
    assert(out.str() == "xxxxx3.142");
    }

    {
    ostringstream out;
    out << scientific << setfill('x') << setprecision(3) << setw(10) << pi;
    assert(out.str() == "x3.142e+00");
    }

    {
    ostringstream out;
    out << setw(10) << pi;
    assert(out.str() == "   3.14159");
    out << left << setfill('x') << setprecision(3) << setw(10) << pi;
    assert(out.str() == "   3.141593.14xxxxxx");
    out.fill(' ');
    out.unsetf(out.flags());
    out.precision(6);
    out << setw(10) << pi;
    assert(out.str() == "   3.141593.14xxxxxx   3.14159");
    }

    {
    ostringstream out;
    const char               fill      = out.fill();
    const ios_base::fmtflags flags     = out.flags();
    const streamsize         precision = out.precision();
    out << setw(10) << pi;
    assert(out.str() == "   3.14159");
    out << left << setfill('x') << setprecision(3) << setw(10) << pi;
    assert(out.str() == "   3.141593.14xxxxxx");
    out.fill(fill);
    out.flags(flags);
    out.precision(precision);
    out << setw(10) << pi;
    assert(out.str() == "   3.141593.14xxxxxx   3.14159");
    }

    cout << "Done." << endl;
    return 0;}
