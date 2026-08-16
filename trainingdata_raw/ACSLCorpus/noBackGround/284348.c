#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((((a) < (c) || ((a) == (c) && (b) <= (d))) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result = false;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    if (a < c) {
        result = true;
    } else if (a == c) {
        if (b <= d) {
            result = true;
        }
    }
    
    return result;
}
