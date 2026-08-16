#include <stdbool.h>

/*@
    predicate sum_ge_5(integer a, integer b, integer c, integer d, integer e, integer k) =
        a + b + c + d + e + k >= 5;

    predicate sum_lt_e(integer a, integer b, integer c, integer d, integer e, integer k) =
        a + b + c + d + k < e;

    lemma sum_bounds:
        \forall integer a, b, c, d, e, k;
            a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0 &&
            a + b + c + d + e + k <= 123 &&
            a + b + c + d + e + k >= 5 &&
            k < e ==>
            sum_ge_5(a, b, c, d, e, k);
*/

/*@
    requires a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0;
    requires a + b + c + d + e + k <= 123;
    requires a + b + c + d + e + k >= 5;
    requires k < e;
    ensures \result == (a + b + c + d + e + k >= 5 && a + b + c + d + k < e);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long x;
    bool result;

    x = a + b + c + d + e + k;

    //@ assert sum_ge_5(a, b, c, d, e, k);
    
    if (a + b + c + d + k < e)
    {
        result = true;
        //@ assert sum_lt_e(a, b, c, d, e, k);
        return result;
    }
    else
    {
        //@ assert !sum_lt_e(a, b, c, d, e, k);
        result = false;
        return result;
    }
}
