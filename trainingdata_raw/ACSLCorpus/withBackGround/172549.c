#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
 */

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a < b && b < c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int state = 0;

    //@ ghost int old_state = state;

    if (a < b)
    {
        //@ assert state == old_state;
        state += 1;
        //@ assert state == old_state + 1;
    }

    //@ ghost old_state = state;

    if (b < c)
    {
        //@ assert state == old_state;
        state += 2;
        //@ assert state == old_state + 2;
    }

    //@ assert state == 3 <==> (a < b && b < c);

    return state == 3;
}
