#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 200;
    predicate sum_in_range(integer a, integer b) = 1 <= a + b <= 200;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    //@ assert sum_in_range(a, b);
    
    if (x <= a + b && a <= x) {
        return true;
    } else {
        return false;
    }
}
