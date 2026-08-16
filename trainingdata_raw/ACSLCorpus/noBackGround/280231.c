#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result == (((a) * (b)) > ((c) * (d)));
*/
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    // Variable declarations at top of scope
    unsigned long long ab;
    unsigned long long cd;
    bool result;

    //@ assert ((a) * (b)) <= 10000;
    //@ assert ((c) * (d)) <= 10000;

    ab = a * b;
    cd = c * d;
    result = ab > cd;
    return result;
}
