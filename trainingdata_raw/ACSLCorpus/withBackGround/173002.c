#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 100;
    predicate non_zero(integer v) = v != 0;
    predicate safe_mul(integer a, integer b) = a * b <= 10000;
*/

/*@
    requires in_range(x) && in_range(y) && in_range(z);
    requires non_zero(y);
    ensures \result == (x * z <= y * z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert x <= 100;
    //@ assert y <= 100;
    //@ assert z <= 100;
    //@ assert safe_mul(y, z);
    //@ assert safe_mul(x, z);
    
    result = (x * z <= y * z);
    return result;
}
