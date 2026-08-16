#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (c > a ? a + b >= d : c + d >= a);
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;
    
    if (c > a)
    {
        //@ assert c > a;
        result = (a + b >= d);
    }
    else
    {
        //@ assert c <= a;
        result = (c + d >= a);
    }
    
    return result;
}
