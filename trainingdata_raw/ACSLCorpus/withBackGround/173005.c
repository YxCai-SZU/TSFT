#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    
    predicate k_in_range(integer k) =
        0 <= k && k <= 123;
    
    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) ? 1 : 0;
*/

/*@
    requires is_valid_range(a, b, c, d, e);
    requires k_in_range(k);
    ensures \result == (condition_holds(a, b, c, d, e, k) == 1);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    //@ assert is_valid_range(a, b, c, d, e);
    
    if (b - a <= k) {
        //@ assert condition_holds(a, b, c, d, e, k) == 1;
        return true;
    }
    
    if (c - a <= k) {
        //@ assert condition_holds(a, b, c, d, e, k) == 1;
        return true;
    }
    
    if (d - a <= k) {
        //@ assert condition_holds(a, b, c, d, e, k) == 1;
        return true;
    }
    
    if (e - a <= k) {
        //@ assert condition_holds(a, b, c, d, e, k) == 1;
        return true;
    }
    
    //@ assert condition_holds(a, b, c, d, e, k) == 0;
    return false;
}
