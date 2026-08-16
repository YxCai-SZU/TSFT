#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate product_in_range(integer a, integer b) = a * b <= 100 * 100;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product_in_range(a, b);
    return a * b;
}
