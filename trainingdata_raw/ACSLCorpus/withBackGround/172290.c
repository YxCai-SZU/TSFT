#include <stdint.h>

/*@
    predicate nonnegative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;
    
    predicate k_in_range(integer k, integer a, integer b, integer c) =
        1 <= k <= a + b + c;
*/

/*@
    requires nonnegative(a, b, c);
    requires k_in_range(k, a, b, c);
    ensures \result >= -1 * c;
    ensures \result <= a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res;
    int64_t k_mut;
    
    res = 0;
    k_mut = k;
    
    if (a < k_mut)
    {
        res += a;
        k_mut -= a;
    }
    else
    {
        res = k_mut;
        //@ assert res >= -1 * c;
        return res;
    }
    
    if (b < k_mut)
    {
        k_mut -= b;
    }
    else
    {
        //@ assert res <= a;
        return res;
    }
    
    if (c < k_mut)
    {
        res -= c;
    }
    else
    {
        res -= k_mut;
    }
    
    //@ assert res >= -1 * c;
    //@ assert res <= a;
    
    return res;
}
