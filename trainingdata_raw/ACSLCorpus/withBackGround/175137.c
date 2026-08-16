#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer safe_product(integer n, integer a) = n * a;

    lemma product_bound:
        \forall integer n, integer a;
        valid_params(n, a, 1) ==> safe_product(n, a) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int result;
    /*@ assert valid_params(n, a, b); */
    /*@ assert safe_product(n, a) <= 1000; */
    
    if (n * a < b) {
        result = n * a;
    } else {
        result = b;
    }
    
    /*@ assert result == n * a || result == b; */
    /*@ assert result <= b; */
    return result;
}
