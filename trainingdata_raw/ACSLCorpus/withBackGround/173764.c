#include <limits.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds: \forall integer a, b;
        valid_range(a, b, 100) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int product;
    int res;
    int count;

    //@ assert valid_range(a, b, c);
    product = a * b;
    //@ assert 1 <= product <= 10000;
    res = 0;
    count = product;

    /*@
        loop invariant 0 <= res <= (a * b) / 2;
        loop invariant count == product - 2 * res;
        loop assigns res, count;
        loop variant count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        res += 1;
        count -= 2;
    }

    //@ assert res == (a * b) / 2;
    return res;
}
