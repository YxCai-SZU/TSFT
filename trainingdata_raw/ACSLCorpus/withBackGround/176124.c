#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 1000;
    predicate x_in_range(integer x) = 1 <= x && x <= 10000;
    predicate product_in_range(integer a) = a * 3 <= 1000 * 3;
*/

/*@
    requires x_in_range(x) && a_in_range(a);
    ensures \result == ((a * 3) >= x);
    assigns \nothing;
*/
bool input_tuple(unsigned int x, unsigned int a)
{
    // Variable declarations at scope top
    unsigned int p;
    bool result;

    //@ assert a_in_range(a);
    //@ assert product_in_range(a);
    
    p = a * 3;
    result = (p >= x);
    
    return result;
}
