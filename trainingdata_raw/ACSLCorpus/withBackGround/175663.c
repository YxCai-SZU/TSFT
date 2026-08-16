#include <stdbool.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 9;

    lemma product_bound:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> x * y <= 81;
*/

/*@
    requires 1 <= x <= 9;
    requires 1 <= y <= 9;
    ensures \result == ((x * y) % 2 == 0);
    assigns \nothing;
*/
bool my_loop_isolation_example(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    bool result;
    unsigned int product;

    //@ assert bounds(x);
    //@ assert bounds(y);
    
    product = x * y;
    //@ assert product <= 81;
    
    result = (product % 2 == 0);
    return result;
}
