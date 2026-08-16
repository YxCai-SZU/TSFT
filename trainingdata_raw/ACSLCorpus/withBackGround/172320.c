#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10000;
    predicate b_in_range(integer b) = 1 <= b && b <= 10000;
    predicate product_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long c;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product_in_range(a, b);
    
    c = a * b;
    return c % 2 != 0;
}
