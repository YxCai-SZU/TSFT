#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;

    logic integer compute_state(integer a, integer b, integer c) =
        (a < b ? 1 : 2) + (b < c ? 4 : 8);

    lemma state_implies_order:
        \forall integer a, b, c;
            compute_state(a, b, c) == 5 ==> is_ordered(a, b, c);

    lemma order_implies_state:
        \forall integer a, b, c;
            is_ordered(a, b, c) ==> compute_state(a, b, c) == 5;
*/

/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == true <==> a < b && b < c;
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int state = 0;

    if (a < b)
    {
        state += 1;
        //@ assert state == 1;
    }
    else
    {
        state += 2;
        //@ assert state == 2;
    }

    if (b < c)
    {
        state += 4;
        //@ assert state == compute_state(a, b, c);
    }
    else
    {
        state += 8;
        //@ assert state == compute_state(a, b, c);
    }

    //@ assert state == compute_state(a, b, c);
    //@ assert state == 5 <==> is_ordered(a, b, c);

    if (state == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}
