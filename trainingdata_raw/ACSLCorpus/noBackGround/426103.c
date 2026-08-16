#include <stdbool.h>

/*@
    requires ((a) < 0x8000000000 && (b) < 0x8000000000 && (c) < 0x8000000000 &&
        (d) < 0x8000000000 && (e) < 0x8000000000 && (k) < 0x8000000000 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (((e) - (a)) <= k);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    //@ assert e >= a;
    return e - a <= k;
}
