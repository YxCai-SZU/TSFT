#include <stdbool.h>

/*@
    requires (1 <= (x) <= 16) && (1 <= (y) <= 16) && ((x) + (y) <= 16);
    ensures \result == true <==> ((x) <= 8 && (y) <= 8);
    assigns \nothing;
*/
bool func(unsigned long x, unsigned long y)
{
    bool x_is_within_range = false;
    bool y_is_within_range = false;

    //@ assert 1 <= x <= 16;
    //@ assert 1 <= y <= 16;
    //@ assert x + y <= 16;

    if (x <= 8)
    {
        x_is_within_range = true;
    }

    if (y <= 8)
    {
        y_is_within_range = true;
    }

    //@ assert x_is_within_range == (x <= 8);
    //@ assert y_is_within_range == (y <= 8);

    return x_is_within_range && y_is_within_range;
}
