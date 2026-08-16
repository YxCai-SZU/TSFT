#include <stdbool.h>

/*@
    predicate is_sum_ge(integer a, integer b, integer c) =
        a + b >= c;
 */

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 10000;
    ensures \result == (a + b >= c);
 */
bool func(int a, int b, int c)
{
    int state = 0;

    //@ assert 1 <= a <= 5000;
    //@ assert 1 <= b <= 5000;
    //@ assert 1 <= c <= 10000;

    if (a >= c)
    {
        state = 1;
    }
    else if (a + b >= c)
    {
        state = 2;
    }

    //@ assert state > 0 ==> (a >= c || a + b >= c);
    //@ assert (a >= c || a + b >= c) ==> state > 0;

    return state > 0;
}
