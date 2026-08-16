#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 2000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b;
        valid_inputs(a, b, 2000) ==> safe_product(a, b) <= 2000;
*/

/*@
    requires valid_inputs(a, b, c);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    // Variable declarations at top of scope
    int64_t x;
    int64_t ans;

    //@ assert valid_inputs(a, b, c);
    //@ assert safe_product(a, b) <= 2000;

    x = a * b;
    
    if (x < c) {
        ans = x;
    } else {
        ans = c;
    }

    //@ assert ans <= c;
    //@ assert ans >= 0;
    return ans;
}
