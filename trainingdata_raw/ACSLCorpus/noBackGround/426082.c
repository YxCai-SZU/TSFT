#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) <= 123 && (b) <= 123 && (c) <= 123 && (d) <= 123 && (e) <= 123 && (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    //@ assert ((b) - (a)) >= 0 && ((c) - (a)) >= 0 && ((d) - (a)) >= 0 && ((e) - (a)) >= 0;
    
    if (b - a <= k || c - a <= k || d - a <= k || e - a <= k) {
        //@ assert b - a <= k || c - a <= k || d - a <= k || e - a <= k;
        return true;
    } else {
        //@ assert !(b - a <= k || c - a <= k || d - a <= k || e - a <= k);
        return false;
    }
}
