#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100 && 1 <= (y) <= 100);
    ensures \result == true <==> ((x) <= (((y)) * 2) && (y) <= (((x)) * 2));
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    bool result;
    
    //@ assert ((y) * 2) <= 200;
    
    if (x <= y * 2 && y <= x * 2) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
