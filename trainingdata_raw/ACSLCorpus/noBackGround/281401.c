#include <stdbool.h>

/*@
    requires -100 <= x <= 100;
    requires -100 <= y <= 100;
    ensures \result == true <==> (((x) == 0 && -100 <= (y) && (y) <= 100) ||
        ((y) == 0 && -100 <= (x) && (x) <= 100));
    assigns \nothing;
 */
bool func(int x, int y)
{
    int abs_x;
    int abs_y;
    bool result;

    //@ assert -100 <= x <= 100;
    //@ assert -100 <= y <= 100;

    abs_x = (x < 0) ? -x : x;
    abs_y = (y < 0) ? -y : y;

    //@ assert 0 <= abs_x <= 100;
    //@ assert 0 <= abs_y <= 100;

    if (x == 0)
    {
        //@ assert abs_y <= 100;
        result = (abs_y <= 100);
        return result;
    }
    else if (y == 0)
    {
        //@ assert abs_x <= 100;
        result = (abs_x <= 100);
        return result;
    }
    else
    {
        result = false;
        return result;
    }
}
