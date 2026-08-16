#include <stdbool.h>

/*@
    requires ((a) <= 123 && (b) <= 123 && (c) <= 123 && (d) <= 123 && (e) <= 123 &&
        (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    // Variable declarations at scope top
    unsigned long long dist;
    bool result;

    //@ assert e - a == ((e) - (a));
    dist = e - a;
    //@ assert dist == ((e) - (a));
    result = (dist <= k);
    return result;
}
