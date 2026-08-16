#include <stdbool.h>

/*@
    predicate is_sum_32(integer a, integer b) = a + b == 32;
 */

/*@
    requires 0 <= a <= 32;
    requires 0 <= b <= 32;
    ensures \result == (a + b == 32);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;

    //@ assert a + b == a + b;
    c = a + b;

    //@ assert c == a + b;
    return c == 32;
}
