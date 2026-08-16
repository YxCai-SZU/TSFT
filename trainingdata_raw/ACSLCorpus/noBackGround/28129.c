#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == (((c) >= (a) && (c) <= (b)) ? 1 : 0);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    
    result = (c >= a && c <= b);
    
    //@ assert result == (bool)(((c) >= (a) && (c) <= (b)) ? 1 : 0);
    return result;
}
