#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((((d) < (a) || ((c) < (a) && (d) >= (b))) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    if (d < a) {
        result = true;
    } else if (c < a && d >= b) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == ((((d) < (a) || ((c) < (a) && (d) >= (b))) ? 1 : 0) == 1);
    return result;
}
