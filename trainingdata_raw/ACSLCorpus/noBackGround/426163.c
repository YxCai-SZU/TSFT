#include <stdbool.h>

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result == 1 <==> (((((x)) % 2 == 0) && ((1) <= ((y)) && ((y)) <= (4))) || (!(((x)) % 2 == 0) && !(((y)) % 2 == 0)));
*/
bool func(int x, int y)
{
    bool is_even_x;
    bool is_even_y;
    bool result;

    is_even_x = (x % 2 == 0);
    is_even_y = (y % 2 == 0);

    if (is_even_x)
    {
        if (y <= 4)
        {
            //@ assert ((((x)) % 2 == 0) && ((1) <= ((y)) && ((y)) <= (4)));
            result = true;
        }
        else
        {
            //@ assert !((((x)) % 2 == 0) && ((1) <= ((y)) && ((y)) <= (4)));
            result = false;
        }
    }
    else
    {
        if (is_even_y)
        {
            //@ assert !(!(((x)) % 2 == 0) && !(((y)) % 2 == 0));
            result = false;
        }
        else
        {
            //@ assert (!(((x)) % 2 == 0) && !(((y)) % 2 == 0));
            result = true;
        }
    }

    return result;
}
