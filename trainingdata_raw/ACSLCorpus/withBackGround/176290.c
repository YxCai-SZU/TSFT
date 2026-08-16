#include <stdbool.h>

/*@
    predicate is_light(integer v) = 1 <= v <= 8;
    predicate valid_input(integer x, integer y) = 
        1 <= x <= 16 && 1 <= y <= 16 && x + y <= 16;
*/

/*@
    requires valid_input(x, y);
    ensures \result == true <==> (x <= 8 && y <= 8);
    assigns \nothing;
*/
bool func(long x, long y)
{
    bool x_is_light;
    bool y_is_light;
    bool result;

    //@ assert valid_input(x, y);
    
    x_is_light = (x <= 8) ? true : false;
    y_is_light = (y <= 8) ? true : false;
    
    //@ assert x_is_light == true <==> x <= 8;
    //@ assert y_is_light == true <==> y <= 8;
    
    result = x_is_light && y_is_light;
    
    //@ assert result == true <==> (x <= 8 && y <= 8);
    return result;
}
