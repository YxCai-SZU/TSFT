#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (c - b == b - a);
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (c - b == b - a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
