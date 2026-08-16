#include <stdbool.h>

/*@
  requires (1 <= (x) <= 100) && (1 <= (y) <= 100);
  ensures \result == (x <= 3 * y && y <= 3 * x && x != y);
*/
bool func(unsigned long x, unsigned long y)
{
    bool result;
    //@ assert (1 <= (x) <= 100) && (1 <= (y) <= 100);
    
    if (x > 3 * y || y > 3 * x) {
        result = false;
        //@ assert !(x <= 3 * y && y <= 3 * x);
        return result;
    }
    
    if (x == y) {
        result = false;
        //@ assert x == y;
        return result;
    }
    
    //@ assert x <= 3 * y && y <= 3 * x && x != y;
    result = true;
    return result;
}
