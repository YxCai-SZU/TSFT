#include <stdbool.h>

/*@
    predicate a_le_b_plus_one(integer a, integer b) = a <= b + 1;
 */

/*@
    requires a <= b;
    requires b - a <= 10;
    ensures a <= b + 1;
 */
void func(int a, int b)
{
    //@ assert a <= b;
    //@ assert b - a <= 10;
    //@ assert a <= b + 1;
}
