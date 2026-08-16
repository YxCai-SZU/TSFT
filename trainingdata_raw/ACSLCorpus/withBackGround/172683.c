#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer safe_product(integer a, integer n) = a * n;

    lemma product_bound: \forall integer a, integer n;
        valid_params(n, a, 1) ==> safe_product(a, n) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == safe_product(a, n) || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int result;

    //@ assert valid_params(n, a, b);
    //@ assert safe_product(a, n) <= 1000;

    if (a * n < b) {
        result = a * n;
    } else {
        result = b;
    }

    //@ assert result == safe_product(a, n) || result == b;
    //@ assert result <= b;
    return result;
}
