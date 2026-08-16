#include <stdbool.h>

/*@
    requires 1 <= x <= 16;
    requires 1 <= y <= 16;
    requires x + y <= 16;
    ensures \result == true <==> (x <= 8 && y <= 8);
*/
bool func(int x, int y)
{
    bool x_is_strictly_in_range;
    bool y_is_strictly_in_range;
    bool result;
    
    x_is_strictly_in_range = (1 <= x && x <= 8);
    y_is_strictly_in_range = (1 <= y && y <= 8);
    
    if (x_is_strictly_in_range)
    {
        if (y_is_strictly_in_range)
        {
            //@ assert x <= 8 && y <= 8;
            result = true;
        }
        else
        {
            //@ assert !(x <= 8 && y <= 8);
            result = false;
        }
    }
    else
    {
        //@ assert !(x <= 8 && y <= 8);
        result = false;
    }
    
    return result;
}
