#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (a < b && b < c) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> ((a) < (b) && (b) < (c));
    return result;
}
