#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;
    logic integer safe_product(integer x, integer y) = x * y;
    lemma product_bound: \forall integer x, y; valid_range(x) && valid_range(y) ==> safe_product(x, y) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == safe_product(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int y;
    int result;

    x = a;
    y = b;

    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert safe_product(x, y) <= 10000;

    result = x * y;
    return result;
}
