#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == ((((a) < (b) && (b) < (c)) ? 1 : 0) == 1);
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (a < b) {
        if (b < c) {
            result = true;
        } else {
            result = false;
        }
    } else {
        result = false;
    }
    
    //@ assert result == ((((a) < (b) && (b) < (c)) ? 1 : 0) == 1);
    return result;
}
