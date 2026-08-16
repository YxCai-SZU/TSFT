#include <stdbool.h>

/*@
    requires ((1) <= (a) <= (5000));
    requires ((1) <= (b) <= (5000));
    requires ((1) <= (c) <= (10000));
    ensures \result == (c <= a + b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((1) <= (a) <= (5000));
    //@ assert ((1) <= (b) <= (5000));
    //@ assert ((1) <= (c) <= (10000));
    
    result = (c <= a + b);
    return result;
}
