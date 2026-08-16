#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires a < 0x80000000 && b < 0x80000000 && c < 0x80000000;
    requires d < 0x80000000 && e < 0x80000000 && k < 0x80000000;
    requires is_ordered(a, b, c, d, e);
    ensures \result == (k >= 0 || k >= (e - a));
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    //@ assert e >= a;
    //@ assert e - a <= 18446744073709551615ULL;
    
    return k >= 0 || k >= (e - a);
}
