#include <stdint.h>

/*@
    predicate is_small(integer a, integer b) = (a <= 9 && b <= 9);
    predicate is_valid_range(integer a, integer b) = (1 <= a <= 20 && 1 <= b <= 20);
    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b; is_valid_range(a, b) ==> a * b <= 400;
*/

/*@
    requires is_valid_range(a, b);
    ensures is_small(a, b) ==> \result == safe_product(a, b);
    ensures !is_small(a, b) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    int32_t ans;

    //@ assert a <= 20;
    //@ assert b <= 20;
    //@ assert a * b <= 400;

    if (a > 9 || b > 9) {
        ans = -1;
        //@ assert ans == -1;
    } else {
        ans = (int32_t)(a * b);
        //@ assert ans == safe_product(a, b);
    }

    return ans;
}
