#include <limits.h>

/*@
    predicate valid_range(integer val) = 1 <= val <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound1:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 10000;

    lemma product_bound2:
        \forall integer x, y, z;
            valid_range(x) && valid_range(y) && valid_range(z) ==> 
            product(product(x, y), z) <= 1000000;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    requires valid_range(z);
    ensures \result >= 0;
    ensures \result <= 1000000;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    // Variable declarations at scope top
    int w;
    int v;

    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert valid_range(z);
    //@ assert product(x, y) <= 10000;
    //@ assert product(product(x, y), z) <= 1000000;

    w = x * y;
    v = w * z;
    return v;
}
