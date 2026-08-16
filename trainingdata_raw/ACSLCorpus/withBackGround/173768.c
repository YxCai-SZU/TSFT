#include <stdbool.h>

/*@ predicate within_range(integer v) = -100 <= v && v <= 100; */

/*@
    requires within_range(a) && within_range(b) && within_range(c);
    ensures \result == true <==> (a <= c && b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int state = 0;

    //@ assert within_range(a) && within_range(b) && within_range(c);

    if (a <= c)
    {
        state += 1;
    }

    if (b >= c)
    {
        state += 1;
    }

    //@ assert (a <= c && b >= c) ==> (state == 2);
    //@ assert !(a <= c && b >= c) ==> (state != 2);

    if (state == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
