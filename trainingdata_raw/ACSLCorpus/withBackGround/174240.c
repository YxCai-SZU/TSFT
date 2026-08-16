#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_input(a, b) ==> 1 <= product(a, b) && product(a, b) <= 10000;
*/

/*@
    requires valid_input(a, b);
    ensures \result == product(a, b);
    ensures 1 <= \result && \result <= 10000;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t ans;

    //@ assert valid_input(a, b);
    //@ assert 1 <= product(a, b);
    //@ assert product(a, b) <= 10000;

    ans = a * b;
    return ans;
}
