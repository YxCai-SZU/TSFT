#include <stdbool.h>

/*@ requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 10000;
    ensures \result == (c <= a + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int min_ab;
    int diff;

    //@ ghost int ghost_min_ab;
    //@ ghost int ghost_diff;

    // Calculate min_ab
    if (a < b)
    {
        min_ab = a;
        //@ ghost ghost_min_ab = a;
    }
    else
    {
        min_ab = b;
        //@ ghost ghost_min_ab = b;
    }

    //@ assert (((a) < (b) ==> (ghost_min_ab) == (a)) && ((a) >= (b) ==> (ghost_min_ab) == (b)));

    diff = a + b - min_ab;
    //@ ghost ghost_diff = a + b - ghost_min_ab;

    //@ assert ((a) + (b) - (ghost_min_ab)) == ghost_diff;
    //@ assert diff == ghost_diff;

    return c <= a + b;
}
