#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == (e - a <= k);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long diff;
    
    if (a > e) {
        diff = a - e;
    } else {
        diff = e - a;
    }
    
    //@ assert ((diff) == ((e) >= (a) ? (e) - (a) : (a) - (e)));
    //@ assert diff == e - a;
    
    return diff <= k;
}
