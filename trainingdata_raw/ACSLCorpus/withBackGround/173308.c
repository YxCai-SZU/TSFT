#include <stdbool.h>

/*@
    predicate within_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123 &&
        0 <= k && k <= 123;

    logic integer e_minus_a(integer e, integer a) = e > a ? e - a : a - e;

    lemma e_minus_a_nonnegative: \forall integer e, a; e_minus_a(e, a) >= 0;
*/

/*@
    requires within_range(a, b, c, d, e, k);
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int e_minus_a;

    //@ assert within_range(a, b, c, d, e, k);
    
    if (e > a) {
        e_minus_a = e - a;
    } else {
        e_minus_a = a - e;
    }

    //@ assert e_minus_a == e_minus_a(e, a);
    
    if (e_minus_a > k) {
        //@ assert e_minus_a > k;
        return false;
    } else {
        //@ assert e_minus_a <= k;
        //@ assert e - a <= k;
        return true;
    }
}
