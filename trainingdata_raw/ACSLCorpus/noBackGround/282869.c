#include <stdbool.h>

/*@
    requires -100 <= x <= 100;
    requires -100 <= y <= 100;
    ensures \result == true <==> (((x) > 0 && (y) == 0) || ((x) > 0 && (y) > 0) || ((x) == 0 && (y) > 0));
    assigns \nothing;
 */
bool func(long x, long y)
{
    bool result;
    
    //@ assert -100 <= x <= 100 && -100 <= y <= 100;
    
    if (x > 0 && y > 0) {
        //@ assert x > 0 && y > 0;
        result = true;
    } else if (x == 0 && y > 0) {
        //@ assert x == 0 && y > 0;
        result = true;
    } else if (x > 0 && y == 0) {
        //@ assert x > 0 && y == 0;
        result = true;
    } else {
        //@ assert !(x > 0 && y > 0) && !(x == 0 && y > 0) && !(x > 0 && y == 0);
        result = false;
    }
    
    //@ assert result == true <==> (((x) > 0 && (y) == 0) || ((x) > 0 && (y) > 0) || ((x) == 0 && (y) > 0));
    return result;
}
