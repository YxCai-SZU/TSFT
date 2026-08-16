#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        1 <= product(a, b) <= 100 * 100;

    lemma product_no_overflow:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        product(a, b) <= INT_MAX;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= c;
    ensures \result >= 0;
    ensures \result == c || \result == a * b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int product;
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    //@ assert 1 <= a * b <= 100 * 100;
    //@ assert a * b <= INT_MAX;

    product = a * b;

    if (product < c)
    {
        //@ assert product == a * b;
        result = product;
    }
    else
    {
        //@ assert c == c;
        result = c;
    }

    //@ assert result <= c;
    //@ assert result >= 0;
    //@ assert result == c || result == a * b;

    return result;
}
