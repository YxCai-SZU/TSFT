#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;

    logic integer safe_product(integer a, integer b) =
        a * b;

    lemma product_bounds:
        \forall integer a, b;
            valid_range(a, b) ==>
                1 <= safe_product(a, b) <= 400;
*/

/*@
    requires valid_range(a, b);
    ensures \result == a * b || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func_cannot_be_inlined(int a, int b)
{
    // Variable declarations at scope top
    int result;

    if (a < 10 || b < 10)
    {
        result = 0;
    }
    else
    {
        //@ assert valid_range(a, b);
        //@ assert 1 <= a * b <= 400;
        result = a * b;
    }

    return result;
}

/*@
    requires valid_range(a, b);
    ensures \result == a * b || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int c;

    if (a < 10 || b < 10)
    {
        c = func_cannot_be_inlined(a, b);
    }
    else
    {
        //@ assert valid_range(a, b);
        //@ assert 1 <= a * b <= 400;
        c = a * b;
    }

    return c;
}
