#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;
    predicate product_in_range(integer a, integer b) = -1000000 <= a * b <= 1000000;
    predicate triple_product_in_range(integer a, integer b, integer c) = -1000000000 <= a * b * c <= 1000000000;
*/

/*@
    requires in_range(x) && in_range(y) && in_range(z);
    ensures \result == x * y * z;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    //@ assert in_range(x);
    //@ assert in_range(y);
    //@ assert in_range(z);
    //@ assert product_in_range(x, y);
    //@ assert triple_product_in_range(x, y, z);
    //@ assert x * y <= 1000000;
    //@ assert x * y * z <= 1000000000;
    
    return x * y * z;
}
