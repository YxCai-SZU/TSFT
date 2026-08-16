#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 20;

    // Logical computation for multiplication bounds
    logic integer product_bounds(integer n, integer x) = n * x;

    // Lemma about multiplication bounds
    lemma product_in_range:
        \forall integer n, x;
        valid_range(n) && valid_range(x) ==> 1 <= product_bounds(n, x) <= 400;
*/

/*@
    requires valid_range(n) && valid_range(x);
    ensures \result == n * x || \result == x;
    assigns \nothing;
*/
int func(int n, int x)
{
    // Variable declarations at scope top
    int product;
    int result;

    // Precondition ensures no overflow
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= x && x <= 20;

    // Multiplication bounds verification
    //@ assert 1 <= n * x <= 400;

    product = n * x;

    if (product > x) {
        result = product;
    } else {
        result = x;
    }

    // Postcondition verification
    //@ assert result == n * x || result == x;

    return result;
}
