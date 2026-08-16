#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer low, integer high) =
        low <= a && a <= high;

    logic integer compute_product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b;
        valid_range(a, 1, 100) && valid_range(b, 1, 20) ==>
        compute_product(a, b) <= 2000;
*/

/*@
    requires valid_range(a, 1, 100);
    requires valid_range(b, 1, 20);
    requires valid_range(c, 1, 2000);
    ensures \result <= c;
    ensures \result == a * b || \result == c;
*/
int func(int a, int b, int c)
{
    int r;

    //@ assert valid_range(a, 1, 100);
    //@ assert valid_range(b, 1, 20);
    //@ assert valid_range(c, 1, 2000);
    
    //@ assert a * b <= 2000;
    
    r = a * b;
    
    if (r < c)
    {
        //@ assert r == a * b;
        //@ assert r <= c;
        return r;
    }
    else
    {
        //@ assert c <= r;
        //@ assert c <= c;
        return c;
    }
}
