#include <stdbool.h>

/*@
    requires a <= b;
    requires b - a <= 2147483647;
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b;
    //@ assert b - a <= 2147483647;
    
    result = (a <= c && c <= b);
    
    //@ assert result == (a <= c && c <= b);
    return result;
}
